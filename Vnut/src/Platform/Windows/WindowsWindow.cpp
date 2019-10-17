#include "vnutpch.h"

#include "WindowsWindow.h"

#include <glad/glad.h>

#include "Vnut/Utils/Logger.h"
#include "Vnut/Events/Event.h"
#include "Vnut/Events/WindowEvent.h"
#include "Vnut/Events/InputEvent.h"

namespace Vnut {

	WindowsWindow::WindowsWindow(std::string title, unsigned int width, unsigned int height)
	{
		m_data.title = title;
		m_data.width = width;
		m_data.height = height;

		VNUT_CORE_INFO("Creating window \"{0}\" ({1}, {2})", title, width, height);
		if (!glfwInit())
			VNUT_CORE_ERROR("Failed to initialize GLFW!");
		m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(m_window, &m_data);
		glfwMakeContextCurrent(m_window);
		setVSync(true);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			VNUT_CORE_ERROR("Failed to initialize OpenGL context!");
		}

		glfwSetErrorCallback([](int error, const char* description)
			{
				VNUT_CORE_ERROR("GLFW error ({0}): {1}", error, description);
			});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
			{
				WindowCloseEvent event = WindowCloseEvent();
				EventBus::send(&event);
			});

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
			{
				WindowResizeEvent event = WindowResizeEvent(width, height);
				EventBus::send(&event);
			});

		glfwSetWindowPosCallback(m_window, [](GLFWwindow* window, int xPos, int yPos)
			{
				WindowMoveEvent event = WindowMoveEvent(xPos, yPos);
				EventBus::send(&event);
			});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				switch (action)
				{
					case GLFW_PRESS:
					case GLFW_REPEAT:
					{
						KeyPressEvent event = KeyPressEvent(key);
						EventBus::send(&event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleaseEvent event = KeyReleaseEvent(key);
						EventBus::send(&event);
						break;
					}
				}
			});

		glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int key)
			{
				KeyTypeEvent event = KeyTypeEvent(key);
				EventBus::send(&event);
			});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
			{
				MouseMoveEvent event = MouseMoveEvent(xPos, yPos);
				EventBus::send(&event);
			});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
			{
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressEvent event = KeyPressEvent(button);
						EventBus::send(&event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleaseEvent event = KeyReleaseEvent(button);
						EventBus::send(&event);
						break;
					}
				}
			});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				MouseScrollEvent event = MouseScrollEvent(xOffset, yOffset);
				EventBus::send(&event);
			});
	}

	void WindowsWindow::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		m_data.vSync = enabled;
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

}