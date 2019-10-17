#include "vnutpch.h"

#include "Application.h"

#include "Vnut/Utils/Logger.h"
#include "Input.h"

#ifdef VNUT_PLATFORM_WINDOWS
#	include "Platform/Windows/WindowsWindow.h"
#	define VNUT_WINDOW(...) WindowsWindow(__VA_ARGS__)
#endif

namespace Vnut {

	Application* Application::s_instance = nullptr;

	HandlerListMap EventBus::s_handlers = HandlerListMap();

	Application::Application() : m_window(new VNUT_WINDOW())
	{
		s_instance = this;
		//temp
		EventBus::subscribe(this, &Application::onEvent);
	}

	void Application::run()
	{
		while (m_running) {
			m_window->onUpdate();
		}
	}

	//temp
	void Application::onEvent(WindowCloseEvent* event)
	{
		VNUT_CORE_INFO(event->toString());
	}

}