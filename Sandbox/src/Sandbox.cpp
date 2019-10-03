#include <Vnut.h>

class Sandbox : public Vnut::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Vnut::Application* Vnut::createApplication()
{
	return new Sandbox();
}