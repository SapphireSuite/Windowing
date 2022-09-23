# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)

# Sapphire Suite's CMake tools.
add_subdirectory(CMake)



# Project

project(SA_Windowing)
SA_ConfigureProject(SA_Windowing)



# Library

## Main
add_library(SA_Windowing INTERFACE)
SA_ConfigureTarget(SA_Windowing LINK INTERFACE)


## Base
add_library(SA_Windowing_Base STATIC)
SA_ConfigureTarget(SA_Windowing_Base)
SA_TargetSources(SA_Windowing_Base
	PUBLIC_SRC_DIR "Include/SA/Windowing/Base"
	PRIVATE_SRC_DIR "Source/SA/Windowing/Base"
)

### Link dependencies.
target_link_libraries(SA_Windowing_Base PUBLIC SA_Logger SA_Flags SA_Event SA_Maths SA_HI)

### Link to main lib.
target_link_libraries(SA_Windowing INTERFACE SA_Windowing_Base)



# Options

## Add SA_Windowing's tests to build tree.
option(SA_WINDOWING_BUILD_TESTS_OPT "Should build SA_Windowing tests" OFF)

## Add SA_Windowing's sample common to build tree.
option(SA_WINDOWING_SCOMMON_OPT "Should build SA_Windowing sample common" OFF)


## GLFW
option(SA_WINDOWING_GLFW_OPT "Should compile GLFW wrapper" ON)

if(SA_WINDOWING_GLFW_OPT)

	# Compile git submodule ThirdParty/glfw instead
	#find_package(glfw3 REQUIRED FATAL_ERROR)

	add_library(SA_Windowing_GLFW STATIC)
	SA_ConfigureTarget(SA_Windowing_GLFW)
	SA_TargetSources(SA_Windowing_GLFW
		PUBLIC_SRC_DIR "Include/SA/Windowing/GLFW"
		PUBLIC_INCL_DIR "OFF"
		PRIVATE_SRC_DIR "Source/SA/Windowing/GLFW"
	)

	target_link_libraries(SA_Windowing_GLFW
		PUBLIC SA_Windowing_Base
		PRIVATE glfw
	)

	### Link to main lib.
	target_link_libraries(SA_Windowing INTERFACE SA_Windowing_GLFW)

endif()



# Entrypoints

add_subdirectory(ThirdParty)

if(SA_WINDOWING_BUILD_TESTS_OPT OR SA_WINDOWING_SCOMMON_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)

endif()
