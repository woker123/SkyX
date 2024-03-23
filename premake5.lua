outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "SkyX"
    architecture "x64"
    startproject "Sandbox"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }


project "Engine"
    location "Engine"
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
        "%{prj.name}/vender/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SKY_PLATFORM_WINDOWS",
            "SKY_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{Copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "SKY_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "SKY_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SKY_DIST"
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
        "Engine/vender/spdlog/include",
        "Engine/src"
    }

    links
    {
        "Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SKY_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SKY_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SKY_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SKY_DIST"
        optimize "On"

    
