// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <GLFW/GLFWWindowInterface.hpp>

#include <SA/Collections/Debug>

namespace SA
{
	namespace GLFW
	{
		void WindowInterface::Create()
		{
			SA_LOG(L"Window Interface created.", Infos, SA/Windowing/GLFW);
		}

		void WindowInterface::Destroy()
		{
			SA_LOG(L"Window Interface destroyed.", Infos, SA/Windowing/GLFW);
		}
	}
}
