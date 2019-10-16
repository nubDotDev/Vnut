#include "vnutpch.h"

#include "WindowsWindow.h"
#include "Vnut/Utils/Logger.h"

namespace Vnut {

	static void GLFWErrorCallback(int error, const char* description)
	{
		VNUT_CORE_ERROR("GLFW error ({0}): {1}", error, description);
	}

	WindowsWindow::WindowsWindow(std::string title, unsigned int width, unsigned int height)
	{
		m_data.title = title;
		m_data.width = width;
		m_data.height = height;

		VNUT_CORE_INFO("Creating window {0} ({1}, {2})", title, width, height);
		if (!glfwInit())
			VNUT_CORE_ERROR("GLFW initialization failed!");
		m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(m_window, &m_data);
		glfwSetErrorCallback(GLFWErrorCallback);
		glfwMakeContextCurrent(m_window);
		setVSync(true);
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