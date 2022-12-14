// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include "GLFWWindowInterface.hpp"

#include <SA/Collections/Debug>

#include "GLFWAPI.hpp"

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

			input.Create();

			SA_LOG(L"Window Interface created.", Infos, SA/Windowing/GLFW);
		}

		void WindowInterface::Destroy()
		{
			AWindowInterface::Destroy();

			input.Destroy();

			glfwTerminate();

			SA_LOG(L"Window Interface destroyed.", Infos, SA/Windowing/GLFW);
		}


		void WindowInterface::Clear()
		{
			AWindowInterface::Clear();

			input.Clear();

			mWindows.Clear();
			
			SA_LOG(L"Window Interface cleared.", Infos, SA/Windowing/GLFW);
		}


		AInputInterface* WindowInterface::GetInputInterface()
		{
			return &input;
		}


		AWindow* WindowInterface::CreateWindow(const WindowCreateInfos& _infos)
		{
			CheckCreated();

			Window* const win = mWindows.Emplace();
			
			win->Create(_infos);

			return win;
		}

		void WindowInterface::DestroyWindow(AWindow* _window)
		{
			CheckCreated();

			mWindows.Erase(_window);
		}

	#if SA_RENDER_VULKAN_IMPL

		bool WindowInterface::VkQueryRequiredExtensions(std::vector<const char*>& _extensions) const
		{
			CheckCreated();

			uint32_t extensionCount = 0;
			const char** rawExtensions = nullptr;

			rawExtensions = glfwGetRequiredInstanceExtensions(&extensionCount);

			_extensions.reserve(extensionCount);
			_extensions.insert(_extensions.end(), rawExtensions, rawExtensions + extensionCount);

			return true;
		}

	#endif
	}
}
