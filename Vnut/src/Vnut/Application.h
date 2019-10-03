#pragma once

#include "Core.h"

namespace Vnut {

	class VNUT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// Defined by client
	Application* createApplication();

}