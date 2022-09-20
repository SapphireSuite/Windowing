// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Collections/Debug>
using namespace SA;

#include <main_common.hpp>
#include <SA/Windowing/GLFW/GLFWWindowInterface.hpp>

int main()
{
	GLFW::WindowInterface interface;

	return main_common(&interface);
}
