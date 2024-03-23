#pragma once
#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Sky
{
	class SKY_API Log
	{
	public:
		static void Init();
		static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_coreLogger; }
		static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_clientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}

#define SKY_CORE_TRACE(...)			::Sky::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SKY_CORE_INFO(...)			::Sky::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SKY_CORE_WARN(...)			::Sky::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SKY_CORE_ERROR(...)			::Sky::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SKY_CORE_FATAL(...)			::Sky::Log::GetCoreLogger()->fatal(__VA_ARGS__);

#define SKY_TRACE(...)			::Sky::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SKY_INFO(...)			::Sky::Log::GetClientLogger()->info(__VA_ARGS__)
#define SKY_WARN(...)			::Sky::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SKY_ERROR(...)			::Sky::Log::GetClientLogger()->error(__VA_ARGS__)
#define SKY_FATAL(...)			::Sky::Log::GetClientLogger()->fatal(__VA_ARGS__);