// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_WINDOWING_GLFW_WINDOW_INTERFACE_GUARD
#define SAPPHIRE_WINDOWING_GLFW_WINDOW_INTERFACE_GUARD

#include <SA/Windowing/Base/AWindowInterface.hpp>

#include <SA/HI/InterfaceList.hpp>

#include "GLFWWindow.hpp"
#include "GLFWInputInterface.hpp"

namespace SA
{
	namespace GLFW
	{
		class WindowInterface : public AWindowInterface
		{
			InputInterface input;

			HI::InterfaceList<Window> mWindows;

		public:
			void Create() override final;
			void Destroy() override final;

			void Clear() override final;

			AInputInterface* GetInputInterface() override final;

			AWindow* CreateWindow(const WindowCreateInfos& _infos) override final;
			void DestroyWindow(AWindow* _window) override final;

		#if SA_RENDER_VULKAN_IMPL

			bool VkQueryRequiredExtensions(std::vector<const char*>& _extensions) const override final;

		#endif
		};
	}
}

#endif // SAPPHIRE_WINDOWING_GLFW_WINDOW_INTERFACE_GUARD
