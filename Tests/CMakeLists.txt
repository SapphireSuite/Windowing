# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

# Entrypoints

add_subdirectory(Prototype_Common)

if(SA_WINDOWING_GLFW_OPT)

	add_subdirectory(Prototype_GLFW)

endif()

add_subdirectory(Prototype_All)

add_subdirectory(UnitTests)
