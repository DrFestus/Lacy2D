#pragma once

#include "Lacy2D/Core/Window.h"

#include <SFML/Graphics.hpp>

namespace Lacy2D {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; }

		sf::RenderWindow& GetSFMLWindow() { return *m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		sf::RenderWindow* m_Window;
		sf::Color m_BackgroundColor = sf::Color::Black;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}

