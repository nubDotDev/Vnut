#pragma once

#include "Core.h"

//#include "Vnut/Events/Event.h"

namespace Vnut {

	class VNUT_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void run();
	private:
		//std::unique_ptr<EventBus> m_eventBus;
	};
	 
	// Defined by client
	Application* createApplication();

}