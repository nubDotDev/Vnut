#include "vnutpch.h"

#include "Logger.h"

namespace Vnut {

	std::shared_ptr<spdlog::logger> Logger::s_clientLogger;
	std::shared_ptr<spdlog::logger> Logger::s_coreLogger;

	void Logger::init()
	{
		// [H:M:S] NAME LEVEL: MESSAGE
		spdlog::set_pattern("[%T] %^%n %l: %v%$");
		s_clientLogger = spdlog::stdout_color_mt("APP");
		s_coreLogger = spdlog::stdout_color_mt("VNUT");
	}

}