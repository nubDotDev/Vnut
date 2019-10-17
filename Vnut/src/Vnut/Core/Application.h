#pragma once

#include "Core.h"
#include "Window.h"
#include "Vnut/Events/Event.h"
//temp
#include "Vnut/Events/WindowEvent.h"

namespace Vnut {

	class VNUT_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		static inline Application* instance() { return s_instance; }

		inline Window& getWindow() { return *m_window; }

		void run();
	private:
		static Application* s_instance;

		bool m_running = true;

		std::unique_ptr<Window> m_window;

		//temp
		void onEvent(WindowCloseEvent* event);
	};
	
	// Defined by client
	Application* createApplication();

}