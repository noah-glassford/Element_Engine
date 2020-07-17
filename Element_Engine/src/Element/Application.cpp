#include "Application.h"
#include <Event\ApplicationEvent.h>
#include <Element\Log.h>

namespace ELM
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		ELM_TRACE(e);
		
		while (true);
	}
}