#pragma once

#include "Core.h"

namespace ELM
{

	class ELM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	
	};
	//To be defined in CLIENT
	Application* CreateApplication();
}