#pragma once
#ifdef ELM_PLATFORM_WINDOWS

extern ELM::Application* ELM::CreateApplication();
int main(int argc, char** argv)
{
	printf("fuck you");
	auto app = ELM::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Element Only support Windows
#endif