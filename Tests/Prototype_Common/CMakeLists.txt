# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

# Executable

## Add executable target.
add_library(SA_WindowingProto_Common STATIC "main_common.cpp")

target_include_directories(SA_WindowingProto_Common PUBLIC .)


# Dependencies

### Add library dependencies.
target_link_libraries(SA_WindowingProto_Common PUBLIC SA_Windowing)
