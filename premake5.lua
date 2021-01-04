workspace "GameEngine"
    architecture "x64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "GameEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "GameEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "GameEngine/vendor/imgui"
IncludeDir["glm"] = "GameEngine/vendor/glm"

include "GameEngine/vendor/GLFW"
include "GameEngine/vendor/Glad"
include "GameEngine/vendor/imgui"

project "GameEngine"
    location "GameEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "gepch.h"
    pchsource "GameEngine/src/gepch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    defines {
        "_CRT_SECURE_NO_WARNINGS"
    }
    
    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "GE_PLATFORM_WINDOWS",
            "GE_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "GE_DEBUG"
        runtime "Debug"
        symbols  "on"
    
    filter "configurations:Release"
        defines "GE_RELEASE"
        runtime "Release"
        optimize  "on"
        
    filter "configurations:Dist"
        defines "GE_DIST"
        runtime "Release"
        optimize  "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }
    
    includedirs {
        "GameEngine/vendor/spdlog/include",
        "GameEngine/src",
        "GameEngine/vendor",
        "%{IncludeDir.glm}"
    }

    links {
        "GameEngine"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "GE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "GE_DEBUG"
        runtime "Debug"
        symbols  "on"
    
    filter "configurations:Release"
        defines "GE_RELEASE"
        runtime "Release"
        optimize  "on"
        
    filter "configurations:Dist"
        defines "GE_DIST"
        runtime "Release"
        optimize  "on"
