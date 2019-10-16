#include "vnutpch.h"

#include "Application.h"
#include "Vnut/Utils/Logger.h"

namespace Vnut {

	Application::Application() : m_window(new VNUT_WINDOW()) {}

	void Application::run()
	{
		while (m_running) {
			m_window->onUpdate();
		}
	}

}