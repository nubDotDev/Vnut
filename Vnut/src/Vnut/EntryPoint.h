#pragma once

#ifdef VNUT_PLATFORM_WINDOWS

extern Vnut::Application* Vnut::createApplication();

int main(int argc, char** argv)
{
	auto application = Vnut::createApplication();
	application->run();
	delete application;
}

#endif