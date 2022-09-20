# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)

# Sapphire Suite's CMake tools.
add_subdirectory(CMake)



# Project

project(SA_Windowing)
SA_ConfigureProject(SA_Windowing)



# Library

add_library(SA_Windowing STATIC)
SA_ConfigureTarget(TARGET SA_Windowing)
SA_TargetSources(TARGET SA_Windowing
	PUBLIC_FOLDER "Include/SA/Windowing/Base"
	PRIVATE_FOLDER "Source/SA/Windowing/Base"
	TOGGLE_INCLUDE_DIR OFF
)

## Manual include directory: custom target sources
target_include_directories(SA_Windowing PUBLIC Include)
target_include_directories(SA_Windowing PRIVATE Include/SA/Windowing)

### Link dependencies.
target_link_libraries(SA_Windowing PUBLIC SA_Logger SA_Flags SA_Event SA_Maths SA_HI)



# Options

## Add SA_Windowing's tests to build tree.
option(SA_WINDOWING_BUILD_TESTS_OPT "Should build SA_Windowing tests" OFF)


## GLFW
option(SA_WINDOWING_GLFW_OPT "Should compile GLFW wrapper" ON)

if(SA_WINDOWING_GLFW_OPT)

	find_package(glfw3 REQUIRED FATAL_ERROR)
	target_link_libraries(SA_Windowing PUBLIC glfw)

	target_compile_definitions(SA_Windowing PUBLIC SA_WINDOWING_GLFW)
	SA_TargetSources(TARGET SA_Windowing
		PUBLIC_FOLDER "Include/SA/Windowing/GLFW"
		PRIVATE_FOLDER "Source/SA/Windowing/GLFW"
		TOGGLE_INCLUDE_DIR OFF
	)

endif()



# Entrypoints

add_subdirectory(ThirdParty)

if(SA_WINDOWING_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)

endif()
