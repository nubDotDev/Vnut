#pragma once

#ifdef VNUT_PLATFORM_WINDOWS
	#ifdef VNUT_BUILD_DLL
		#define VNUT_API __declspec(dllexport)
	#else
		#define VNUT_API __declspec(dllimport)
	#endif
#endif