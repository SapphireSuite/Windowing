# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

# Executable

## Add executable target.
add_executable(SA_WindowingProto_GLFW "main.cpp")



# Dependencies

### Add library dependencies.
target_link_libraries(SA_WindowingProto_GLFW PRIVATE SA_WindowingProto_Common)



# Tests

add_test(NAME CSA_WindowingProto_GLFW COMMAND SA_WindowingProto_GLFW)
