#pragma once

#ifdef ELM_PLATFORM_WINDOWS
	#ifdef ELM_BUILD_DLL
		#define ELM_API __declspec(dllexport)
	#else
		#define ELM_API __declspec(dllimport)
	#endif
#else
	#error Element Only support Windows
#endif

#define BIT(x) (1 << x)