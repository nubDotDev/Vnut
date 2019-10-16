#pragma once

#include "Core.h"
#include "Window.h"
#include "Vnut/Events/Event.h"

namespace Vnut {

	class VNUT_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void run();
	private:
		bool m_running = true;

		std::unique_ptr<Window> m_window;
	};
	 
	// Defined by client
	Application* createApplication();

}