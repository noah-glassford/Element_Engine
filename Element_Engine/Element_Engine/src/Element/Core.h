#pragma once

#ifdef ELM_PLATFORM_WINDOWS
	#ifdef ELM_BUILD_DLL
		#define ELEMENT_API __declspec(dllexport)
	#else
		#define ELEMENT_API __declspec(dllimport)
	#endif
#else
	#error Element Only support Windows
#endif