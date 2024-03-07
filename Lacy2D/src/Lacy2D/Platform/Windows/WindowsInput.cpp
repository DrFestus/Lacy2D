#include "lacy2Dpch.h"

#include "WindowsInput.h"
#include "Lacy2D/Events/ApplicationEvent.h"
#include "Lacy2D/Core/Application.h"


#include <SFML/Window.hpp>

namespace Lacy2D {

	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(keycode));
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(button));
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl() {
		auto [x, y] = sf::Mouse::getPosition(); // Consider the context (relative to window or global)
		return { static_cast<float>(x), static_cast<float>(y) };
	}

	float WindowsInput::GetMouseXImpl() {
		auto [x, y] = GetMousePositionImpl(); // Use structured binding for simplicity
		return x;
	}

	float WindowsInput::GetMouseYImpl() {
		auto [x, y] = GetMousePositionImpl(); // Use structured binding for simplicity
		return y;
	}
}