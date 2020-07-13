#include <Element.h>

class Sandbox : public ELM::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

ELM::Application* ELM::CreateApplication()
{
	return new Sandbox();
}