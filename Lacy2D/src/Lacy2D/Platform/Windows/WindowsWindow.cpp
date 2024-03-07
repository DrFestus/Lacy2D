#include "lacy2Dpch.h"
#include "WindowsWindow.h"
#include <Lacy2D/Events/ApplicationEvent.h>
#include <Lacy2D/Events/KeyEvent.h>
#include <Lacy2D/Events/MouseEvent.h>
#include <Lacy2D/Core/Log.h>

namespace Lacy2D {

    static bool s_SFMLInitialized = false;

    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {

    }

    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        LACY2D_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_SFMLInitialized)
        {
            LACY2D_CORE_ASSERT(success, "Could not intialize SFML!");
            s_SFMLInitialized = true;
        }


        m_Window = new sf::RenderWindow(sf::VideoMode((int)props.Width, (int)props.Height), m_Data.Title.c_str());
        SetVSync(true);
    }

    void WindowsWindow::Shutdown()
    {
        delete m_Window;
        m_Window = nullptr;
    }

    void WindowsWindow::OnUpdate() {
        sf::Event sfEvent;
        while (m_Window->pollEvent(sfEvent)) {
            switch (sfEvent.type) {
            case sf::Event::Closed: {
                WindowCloseEvent e;
                m_Data.EventCallback(e);
                break;
            }
            case sf::Event::Resized: {
                WindowResizeEvent e(sfEvent.size.width, sfEvent.size.height);
                m_Data.Width = sfEvent.size.width;
                m_Data.Height = sfEvent.size.height;
                m_Data.EventCallback(e);
                break;
            }

            }
        }
    }


    void WindowsWindow::SetVSync(bool enabled)
    {
        m_Window->setVerticalSyncEnabled(enabled);
        m_Data.VSync = enabled;

        LACY2D_CORE_INFO("VSync {}", enabled ? "enabled" : "disabled");
    }


    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }


}