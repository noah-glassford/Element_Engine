workspace "Element_Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Element_Engine"
	location "Element_Engine"
	kind "SharedLib"
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
		"Element_Engine/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"ELM_PLATFORM_WINDOWS",
			"ELM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ELM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ELM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ELM_DIST"
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
		"Element_Engine/vendor/spdlog/include",
		"Element_Engine/src"
	}

	links
	{
		"Element_Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"ELM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ELM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ELM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ELM_DIST"
		optimize "On" 