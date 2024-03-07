// Application.cpp
#include "lacy2Dpch.h"

#include "Application.h"

#include "Lacy2D/Events/ApplicationEvent.h"
#include "Log.h"

namespace Lacy2D {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		LACY2D_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		#if defined(DEBUG) | defined(_DEBUG)
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
			_CrtSetDbgFlag(_CRTDBG_CHECK_ALWAYS_DF);
		#endif

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Lacy2D::Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));

		LACY2D_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		//e.Handled(true);
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e) {

		return true;
	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
			// Your application's update and rendering logic here
		}
	}
}