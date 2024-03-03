workspace "Lacy2D"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SFML"] = "Lacy2D/vendor/SFML/include"
IncludeDir["ImGui"] = "Lacy2D/vendor/imgui"
IncludeDir["ImGuiSFML"] = "Lacy2D/vendor/imgui-sfml"
IncludeDir["asio"] = "Lacy2D/vendor/asio/asio/include"
IncludeDir["json"] = "Lacy2D/vendor/json/include"
IncludeDir["mysqlconnectorcpp"] = "Lacy2D/vendor/mysql-connector-cpp/include"

include "Lacy2D/vendor/imgui"
include "Lacy2D/vendor/imgui-sfml"

project "Lacy2D"
	location "Lacy2D"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.SFML}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.ImGuiSFML}",
		"%{IncludeDir.asio}",
		"%{IncludeDir.json}",
		"%{IncludeDir.mysqlconnectorcpp}"
	}

	libdirs 
	{ 
		"%{prj.name}/vendor/SFML/lib",
		"%{prj.name}/vendor/imgui/bin/",
		"%{prj.name}/vendor/imgui-sfml/bin/"
	}

	links
	{
		"ImGui",
		"ImGui-SFML"
	}

	externalincludedirs
	{
		"%{prj.name}/vendor/SFML/include"
	}

	syslibdirs
	{
		"%{prj.name}/vendor/SFML/lib" 
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LACY2D_PLATFORM_WINDOWS",
			"LACY2D_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Client"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Server")
		}

	filter "configurations:Debug"
		defines "LACY2D_DEBUG"
		runtime "Debug"		
		symbols "On"
		links
		{
			"sfml-system-d.lib",	
			"sfml-window-d.lib",
			"sfml-graphics-d.lib",
			"sfml-audio-d.lib",
			"sfml-network-d.lib"
		}

	filter "configurations:Release"
		defines "LACY2D_RELEASE"
		runtime "Release"		
		optimize "On"
		links
		{
			"sfml-system.lib",
			"sfml-window.lib",
			"sfml-graphics.lib",
			"sfml-audio.lib",
			"sfml-network.lib"
		}

	filter "configurations:Dist"
		defines "LACY2D_DIST"
		runtime "Release"		
		optimize "On"
		links
		{
			"sfml-system.lib",
			"sfml-window.lib",
			"sfml-graphics.lib",
			"sfml-audio.lib",
			"sfml-network.lib",
		}

project "Client"
	location "Client"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.SFML}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.ImGuiSFML}",
		"%{IncludeDir.asio}",
		"%{IncludeDir.json}",
		"%{IncludeDir.mysqlconnectorcpp}"
	}

	libdirs 
	{ 
		"Lacy2D/vendor/SFML/lib"
	}

	syslibdirs
	{
		"Lacy2D/vendor/SFML/lib" 
	}

	links
	{
		"Lacy2D"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"LACY2D_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LACY2D_DEBUG"
		runtime "Debug"
		symbols "on"
		links
		{
			"sfml-system-d.lib",	
			"sfml-window-d.lib",
			"sfml-graphics-d.lib",
			"sfml-audio-d.lib",
			"sfml-network-d.lib"
		}

	filter "configurations:Release"
		defines "LACY2D_RELEASE"
		runtime"Release"		
		optimize "On"
		links
		{
			"sfml-system.lib",
			"sfml-window.lib",
			"sfml-graphics.lib",
			"sfml-audio.lib",
			"sfml-network.lib"
		}

	filter "configurations:Dist"
		defines "LACY2D_DIST"
		runtime "Release"		
		optimize "On"
		links
		{
			"sfml-system.lib",
			"sfml-window.lib",
			"sfml-graphics.lib",
			"sfml-audio.lib",
			"sfml-network.lib",
		}

project "Server"
	location "Server"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.SFML}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.ImGuiSFML}",
		"%{IncludeDir.asio}",
		"%{IncludeDir.json}",
		"%{IncludeDir.mysqlconnectorcpp}"
	}

	libdirs 
	{ 
		"Lacy2D/vendor/SFML/lib"
	}

	syslibdirs
	{
		"Lacy2D/vendor/SFML/lib" 
	}

	links
	{
		"Lacy2D"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"LACY2D_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LACY2D_DEBUG"
		runtime "Debug"
		symbols "on"
		links
		{
			"sfml-system-d.lib",	
			"sfml-window-d.lib",
			"sfml-graphics-d.lib",
			"sfml-audio-d.lib",
			"sfml-network-d.lib"
		}

	filter "configurations:Release"
		defines "LACY2D_RELEASE"
		runtime"Release"		
		optimize "On"
		links
		{
			"sfml-system.lib",
			"sfml-window.lib",
			"sfml-graphics.lib",
			"sfml-audio.lib",
			"sfml-network.lib"
		}

	filter "configurations:Dist"
		defines "LACY2D_DIST"
		runtime "Release"		
		optimize "On"
		links
		{
			"sfml-system.lib",
			"sfml-window.lib",
			"sfml-graphics.lib",
			"sfml-audio.lib",
			"sfml-network.lib",
		}