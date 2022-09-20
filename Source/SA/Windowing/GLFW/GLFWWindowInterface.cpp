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
			AWindowInterface::Create();

			glfwSetErrorCallback(ErrorCallback);

			SA_ASSERT_EXEC(Default, SA/Windowing/GLFW, glfwInit(), L"GLFW init failed!");

			SA_LOG(L"Window Interface created.", Infos, SA/Windowing/GLFW);
		}

		void WindowInterface::Destroy()
		{
			AWindowInterface::Destroy();

			glfwTerminate();

			SA_LOG(L"Window Interface destroyed.", Infos, SA/Windowing/GLFW);
		}


		void WindowInterface::Clear()
		{
			AWindowInterface::Clear();

			mWindows.Clear();
			
			SA_LOG(L"Window Interface cleared.", Infos, SA/Windowing/GLFW);
		}


		AWindow* WindowInterface::CreateWindow(const WindowCreateInfos& _infos)
		{
			Window* const win = mWindows.Emplace();
			
			win->Create(_infos);

			return win;
		}

		void WindowInterface::DestroyWindow(AWindow* _window)
		{
			mWindows.Erase(_window);
		}
	}
}
