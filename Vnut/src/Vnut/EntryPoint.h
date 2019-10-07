#pragma once

#ifdef VNUT_PLATFORM_WINDOWS

extern Vnut::Application* Vnut::createApplication();

int main(int argc, char** argv)
{
	Vnut::Logger::init();

	auto application = Vnut::createApplication();
	application->run();
	delete application;
}

#endif