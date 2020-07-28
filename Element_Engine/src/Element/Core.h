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

#ifdef ELM_ENABLE_ASSERTS
	#define ELM_ASSERT(x,...) { if(!(x)) {ELM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define ELM_CORE_ASSERT(x, ...)  { if(!(x)) {ELM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define ELM_CORE_ASSERT(x, ...)
	#define ELM_ASSERT (x, ...)

#endif

#define BIT(x) (1 << x)