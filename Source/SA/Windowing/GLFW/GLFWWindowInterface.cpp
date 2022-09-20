// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <GLFW/GLFWWindowInterface.hpp>

#include <SA/Collections/Debug>

namespace SA
{
	namespace GLFW
	{
		void ErrorCallback(int32_t error, const char* description)
		{
			SA_LOG(L"GLFW Error [" << error << L"]:" << description, Error, SA/Windowing/GLFW);
		}

		void WindowInterface::Create()
		{
			glfwSetErrorCallback(ErrorCallback);

			SA_ASSERT_EXEC(Default, SA/Windowing/GLFW, glfwInit(), L"GLFW init failed!");

			SA_LOG(L"Window Interface created.", Infos, SA/Windowing/GLFW);
		}

		void WindowInterface::Destroy()
		{
			glfwTerminate();

			SA_LOG(L"Window Interface destroyed.", Infos, SA/Windowing/GLFW);
		}
	}
}
