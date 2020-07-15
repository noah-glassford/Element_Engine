#pragma once

#ifdef ELM_PLATFORM_WINDOWS

extern ELM::Application* ELM::CreateApplication();
int main(int argc, char** argv)
{
	ELM::Log::Init();
	ELM_CORE_WARN("Initialized Log!");
	int a = 5;
	ELM_INFO("Hello! var={0}", a);

	auto app = ELM::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Element Only support Windows
#endif