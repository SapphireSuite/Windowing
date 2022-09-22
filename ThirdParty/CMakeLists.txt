# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

# Entrypoints

## Sapphire Suite Third Party.
add_subdirectory(SA)

if(SA_WINDOWING_GLFW_OPT)

	add_subdirectory(glfw)

endif(SA_WINDOWING_GLFW_OPT)
