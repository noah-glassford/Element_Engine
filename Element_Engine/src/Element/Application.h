#pragma once
#include "elmpch.h"
#include "Core.h"
#include "Event/Event.h"
#include "Window.h"
#include <Event\ApplicationEvent.h>

namespace ELM
{

	class ELM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = 1;
	
	};
	//To be defined in CLIENT
	Application* CreateApplication();
}
