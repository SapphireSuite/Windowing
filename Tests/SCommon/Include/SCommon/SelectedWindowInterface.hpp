// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_WINDOWING_SCOMMON_SELECTED_WINDOW_INTERFACE_GUARD
#define SAPPHIRE_WINDOWING_SCOMMON_SELECTED_WINDOW_INTERFACE_GUARD

#if SA_WINDOWING_GLFW_IMPL

	#include <SA/Windowing/GLFW/GLFWWindowInterface.hpp>

#endif // SA_WINDOWING_GLFW_IMPL

namespace SA
{
	namespace SCommon
	{
		using SelectedWindowInterface = SA_WINDOWING_SCOMMON_SELECTED_INTERFACE::WindowInterface;
	}
}

#endif // SAPPHIRE_WINDOWING_SCOMMON_SELECTED_WINDOW_INTERFACE_GUARD
