#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "Vnut/Core/Core.h"

namespace Vnut {

	class VNUT_API Logger
	{
	public:
		static void init();

		static inline std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }
		static inline std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_clientLogger;
		static std::shared_ptr<spdlog::logger> s_coreLogger;
	};

}

// Client loggers
#define VNUT_INFO(...)           ::Vnut::Logger::getClientLogger()->info(__VA_ARGS__)
#define VNUT_WARN(...)           ::Vnut::Logger::getClientLogger()->warn(__VA_ARGS__)
#define VNUT_ERROR(...)          ::Vnut::Logger::getClientLogger()->error(__VA_ARGS__)
#define VNUT_CRITICAL(...)       ::Vnut::Logger::getClientLogger()->critical(__VA_ARGS__)

// Core loggers
#define VNUT_CORE_INFO(...)      ::Vnut::Logger::getCoreLogger()->info(__VA_ARGS__)
#define VNUT_CORE_WARN(...)      ::Vnut::Logger::getCoreLogger()->warn(__VA_ARGS__)
#define VNUT_CORE_ERROR(...)     ::Vnut::Logger::getCoreLogger()->error(__VA_ARGS__)
#define VNUT_CORE_CRITICAL(...)  ::Vnut::Logger::getCoreLogger()->critical(__VA_ARGS__)