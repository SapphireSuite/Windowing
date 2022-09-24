#pragma once

#ifndef SAPPHIRE_WINDOWING_GLFW_API_GUARD
#define SAPPHIRE_WINDOWING_GLFW_API_GUARD

/**
*	\file GLFW.hpp
*
*	\brief \b GLFW include support file.
*
*	\ingroup GLFW
*	\{
*/

#if SA_RENDER_VULKAN_IMPL

	#include <vulkan/vulkan.h>

#endif

#include <GLFW/glfw3.h>

/** \} */

#endif // SAPPHIRE_WINDOWING_GLFW_API_GUARD
