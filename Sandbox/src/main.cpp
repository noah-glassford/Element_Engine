#include <Element.h>

class ExampleLayer : public ELM::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		ELM_INFO("ExampleLayer::Update");
	}

	void OnEvent(ELM::Event& event) override
	{
		ELM_TRACE("{0}", event);
	}
};


class Sandbox : public ELM::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

ELM::Application* ELM::CreateApplication()
{
	return new Sandbox();
}