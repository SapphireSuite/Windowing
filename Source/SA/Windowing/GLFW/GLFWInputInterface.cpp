// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <GLFW/GLFWInputInterface.hpp>

#include <SA/Collections/Debug>

#include <GLFW/GLFWAPI.hpp>

namespace SA
{
	namespace GLFW
	{
		void InputInterface::Create()
		{
			AInputInterface::Create();

			SA_LOG(L"Input Interface created.", Infos, SA/Windowing/GLFW);
		}

		void InputInterface::Destroy()
		{
			AInputInterface::Destroy();

			SA_LOG(L"Input Interface destroyed.", Infos, SA/Windowing/GLFW);
		}


		void InputInterface::Clear()
		{
			AInputInterface::Clear();

			SA_LOG(L"Input Interface cleared.", Infos, SA/Windowing/GLFW);
		}


		void InputInterface::Update()
		{
			glfwPollEvents();
		}
	}
}
