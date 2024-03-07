#pragma once

#include "Core.h"
#include "Window.h"
#include "Lacy2D/Events/Event.h"
#include "Lacy2D/Events/ApplicationEvent.h"


namespace Lacy2D {

	class LACY2D_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		Scope<Window> m_Window;
		bool m_Running = true;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}