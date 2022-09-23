# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

# Library Sample Common.

add_library(SA_Windowing_SCommon STATIC)
SA_ConfigureTarget(SA_Windowing_SCommon)
SA_TargetSources(SA_Windowing_SCommon
	PUBLIC_SRC_DIR "Include/SCommon"
	PRIVATE_SRC_DIR "Source/SCommon"
)

target_link_libraries(SA_Windowing_SCommon PUBLIC SA_Windowing)



# Options

## Add SA_Windowing SCommon selected window interface.
option(SA_WINDOWING_SCOMMON_SELECTED_INTERFACE "Use GLFW as selected window interface for scommon implementation." GLFW)
target_compile_definitions(SA_Windowing_SCommon PUBLIC SA_WINDOWING_SCOMMON_SELECTED_INTERFACE=GLFW)
