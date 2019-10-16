#pragma once

#ifdef VNUT_PLATFORM_WINDOWS
#	include "Platform/Windows/WindowsWindow.h"
#	define VNUT_WINDOW(...) WindowsWindow(__VA_ARGS__)
#	ifdef VNUT_BUILD_DLL
#		define VNUT_API __declspec(dllexport)
#	else
#		define VNUT_API __declspec(dllimport)
#	endif
#endif