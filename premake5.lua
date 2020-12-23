workspace "GameEngine"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "GameEngine/vendor/GLFW/include"

include "GameEngine/vendor/GLFW"

project "GameEngine"
    location "GameEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "gepch.h"
    pchsource "GameEngine/src/gepch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }
    
    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "GE_PLATFORM_WINDOWS",
            "GE_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "GE_DEBUG"
        symbols  "On"
    
    filter "configurations:Release"
        defines "GE_RELEASE"
        optimize  "On"
        
    filter "configurations:Dist"
        defines "GE_DIST"
        optimize  "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }
    
    includedirs {
        "GameEngine/vendor/spdlog/include",
        "GameEngine/src"
    }

    links {
        "GameEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "GE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "GE_DEBUG"
        symbols  "On"
    
    filter "configurations:Release"
        defines "GE_RELEASE"
        optimize  "On"
        
    filter "configurations:Dist"
        defines "GE_DIST"
        optimize  "On"