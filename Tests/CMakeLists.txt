# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

# Entrypoints

add_subdirectory(SCommon)

if(SA_WINDOWING_BUILD_TESTS_OPT)

	if(SA_WINDOWING_GLFW_OPT)

		add_subdirectory(Prototype_GLFW)

	endif()

endif(SA_WINDOWING_BUILD_TESTS_OPT)
