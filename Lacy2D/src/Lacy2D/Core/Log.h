#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Lacy2D {

	class LACY2D_API Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		inline static Ref<spdlog::logger>& GetServerLogger() { return s_ServerLogger; }


	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
		static Ref<spdlog::logger> s_ServerLogger;
	};
}

// Core log macros
#define LACY2D_CORE_TRACE(...)     ::Lacy2D::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LACY2D_CORE_INFO(...)      ::Lacy2D::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LACY2D_CORE_WARN(...)      ::Lacy2D::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LACY2D_CORE_ERROR(...)     ::Lacy2D::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LACY2D_CORE_FATAL(...)     ::Lacy2D::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Server log macros
#define LACY2D_SERVER_TRACE(...)     ::Lacy2D::Log::GetServerLogger()->trace(__VA_ARGS__)
#define LACY2D_SERVER_INFO(...)      ::Lacy2D::Log::GetServerLogger()->info(__VA_ARGS__)
#define LACY2D_SERVER_WARN(...)      ::Lacy2D::Log::GetServerLogger()->warn(__VA_ARGS__)
#define LACY2D_SERVER_ERROR(...)     ::Lacy2D::Log::GetServerLogger()->error(__VA_ARGS__)
#define LACY2D_SERVER_FATAL(...)     ::Lacy2D::Log::GetServerLogger()->critical(__VA_ARGS__)

// Client log macros
#define LACY2D_TRACE(...)          ::Lacy2D::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LACY2D_INFO(...)           ::Lacy2D::Log::GetClientLogger()->info(__VA_ARGS__)
#define LACY2D_WARN(...)           ::Lacy2D::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LACY2D_ERROR(...)          ::Lacy2D::Log::GetClientLogger()->error(__VA_ARGS__)
#define LACY2D_FATAL(...)          ::Lacy2D::Log::GetClientLogger()->critical(__VA_ARGS__)