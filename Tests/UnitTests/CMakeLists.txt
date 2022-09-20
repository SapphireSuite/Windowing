# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

SA_FetchGoogleTest()

# Executable

## Inputs

file(GLOB_RECURSE SA_WINDOWING_UT_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_WindowingUT ${SA_WINDOWING_UT_SOURCES})



# Dependencies

### Add library dependencies.
target_link_libraries(SA_WindowingUT PRIVATE SA_Windowing)

### Google test module dependency.
target_link_libraries(SA_WindowingUT PRIVATE gtest)



# Tests

add_test(NAME CSA_WindowingUT COMMAND SA_WindowingUT)
