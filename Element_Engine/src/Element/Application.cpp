#include "elmpch.h"
#include "Application.h"
#include "Event/Event.h"
#include <Element\Log.h>
#include <Event\ApplicationEvent.h>

namespace ELM
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		
		
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}