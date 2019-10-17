#include "vnutpch.h"

#include "WindowsInput.h"

#include "Vnut/Core/Application.h"

namespace Vnut {

	Input* Input::s_instance = new WindowsInput();

	bool WindowsInput::isKeyPressedImpl(int key) const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::instance()->getWindow().getNativeWindow());
		return glfwGetKey(window, key);
	}

	bool WindowsInput::isMouseButtonPressedImpl(int button) const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::instance()->getWindow().getNativeWindow());
		return glfwGetMouseButton(window, button);
	}

	//TODO USE Vector2 INSTEAD OF std::pair
	std::pair<double, double> WindowsInput::getMousePosImpl() const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::instance()->getWindow().getNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return { xPos, yPos };
	}

}