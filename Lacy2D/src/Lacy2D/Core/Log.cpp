#include "lacy2Dpch.h"

#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Lacy2D {

	Ref<spdlog::logger> Log::s_CoreLogger;
	Ref<spdlog::logger> Log::s_ClientLogger;
	Ref<spdlog::logger> Log::s_ServerLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("Lacy");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ServerLogger = spdlog::stdout_color_mt("SERVER");
		s_ServerLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

	}

}