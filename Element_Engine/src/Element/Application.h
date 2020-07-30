#pragma once
#include "elmpch.h"
#include "Core.h"
#include "Event/Event.h"
#include "Window.h"
#include "Element/LayerStack.h"
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = 1;
		LayerStack m_Layerstack;
	
	};
	//To be defined in CLIENT
	Application* CreateApplication();
}
