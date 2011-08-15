solution "rtl.reflection"
	configurations { "Debug", "Release" }
	includedirs { "../../" }
	location "build"

	configuration "Debug"
		targetdir "bin/debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		targetdir "bin/release"
		defines { "NDEBUG" }
		flags { "Optimize" }


	-- Implementation of the library
	project "rtl.reflection"
		kind "StaticLib"
		language "C++"
		files
		{
			"../../rtl/reflection.hpp",
			"../../rtl/reflection/*.hpp",
			"src/*.cpp",
		}

	-- Example showing usage of the class_info
	project "reflection_example"
		kind "ConsoleApp"
		language "C++"
		files
		{
			"examples/class_info_example.cpp"
		}
		links
		{
			"rtl.reflection"
		}
