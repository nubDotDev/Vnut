workspace "Vnut"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Vnut/vendor/glad"
include "Vnut/vendor/GLFW"

project "Vnut"
	location "Vnut"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vnutpch.h"
	pchsource "Vnut/src/vnutpch.cpp"

	files
	{
		"%{prj.name}/src/Vnut/Vnut.h",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/glad/include",
		"%{prj.name}/vendor/GLFW/include",
	}

	links
	{
		"glad",
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VNUT_PLATFORM_WINDOWS",
			"VNUT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "VNUT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VNUT_RELEASE"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Vnut/src",
		"Vnut/vendor",
		"Vnut/vendor/spdlog/include"
	}

	links
	{
		"Vnut"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VNUT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VNUT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VNUT_RELEASE"
		optimize "On"