// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_WINDOWING_GLFW_WINDOW_INTERFACE_GUARD
#define SAPPHIRE_WINDOWING_GLFW_WINDOW_INTERFACE_GUARD

#include <SA/Windowing/Base/AWindowInterface.hpp>

namespace SA
{
	namespace GLFW
	{
		class WindowInterface : public AWindowInterface
		{
		public:
			void Create() override final;
			void Destroy() override final;
		};
	}
}

#endif // SAPPHIRE_WINDOWING_GLFW_WINDOW_INTERFACE_GUARD
