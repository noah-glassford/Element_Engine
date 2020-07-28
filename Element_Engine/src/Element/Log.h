#pragma once


#include "spdlog/spdlog.h"
#include "Core.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
namespace ELM
{
	class ELM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//core log macro
#define ELM_CORE_ERROR(...) ::ELM::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ELM_CORE_WARN(...)  ::ELM::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ELM_CORE_INFO(...)  ::ELM::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ELM_CORE_TRACE(...) ::ELM::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ELM_CORE_FATAL(...) ::ELM::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define ELM_ERROR(...) ::ELM::Log::GetClientLogger()->error(__VA_ARGS__)
#define ELM_WARN(...)  ::ELM::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ELM_INFO(...)  ::ELM::Log::GetClientLogger()->info(__VA_ARGS__)
#define ELM_TRACE(...) ::ELM::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ELM_FATAL(...) ::ELM::Log::GetClientLogger()->fatal(__VA_ARGS__)

//if dist build
//#define HZ_CORE_INFO