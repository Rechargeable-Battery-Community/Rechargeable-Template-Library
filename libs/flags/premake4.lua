solution "rtl.flags"
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

	-- Example showing usage of the flag_set
	project "flag_set_example"
		kind "ConsoleApp"
		language "C++"
		files
		{
			"../../rtl/flags.hpp",
			"../../rtl/flags/*.hpp",
			"../../rtl/flags/detail/*.hpp",
			"examples/flag_set_example.cpp"
		}
