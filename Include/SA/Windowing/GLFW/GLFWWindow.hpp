// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_WINDOWING_GLFW_WINDOW_GUARD
#define SAPPHIRE_WINDOWING_GLFW_WINDOW_GUARD

#include <SA/Windowing/Base/AWindow.hpp>

/**
*	\file GLFWWindow.hpp
* 
*	\brief GLFW implementation of window interface.
* 
*	\ingroup Window
*	\{
*/

struct GLFWwindow;
struct GLFWmonitor;

namespace SA
{
	namespace GLFW
	{
		/// GLFW Window class implementation.
		class Window : public AWindow
		{
			/// Internal GLFW handle.
			GLFWwindow* mHandle = nullptr;

			/// Saved size.
			Vec2ui mSavedSize;

			/// Saved position.
			Vec2i mSavedPosition;


			/**
			*	\brief Minimized Callback bound to GLFW lib.
			* 
			*	\param[in] _handle		GLFW internal handle.
			*	\param[in] _minimized	GLFW new minimized state.
			*/
			static void MinimizedCallback(GLFWwindow* _handle, int32_t _minimized);

			/**
			*	\brief Maximized Callback bound to GLFW lib.
			* 
			*	\param[in] _handle		GLFW internal handle.
			*	\param[in] maximized	GLFW new maximized state.
			*/
			static void MaximizedCallback(GLFWwindow* _handle, int32_t _maximized);

			/**
			*	\brief Resize Callback bound to GLFW lib.
			* 
			*	\param[in] _handle		GLFW internal handle.
			*	\param[in] _width		GLFW new window's width.
			*	\param[in] _height		GLFW new window's height.
			*/
			static void ResizeCallback(GLFWwindow* _handle, int32_t _width, int32_t _height);


			/**
			*	\brief Get this window most used monitor.
			* 
			*	\returns GLFW most used monitor
			*/
			GLFWmonitor* GetCurrentMonitor() const;

		public:
			Vec2ui GetSize() const override final;
			void SetSize(const Vec2ui& _size) override final;

			Vec2ui GetPosition() const override final;
			void SetPosition(const Vec2ui& _size) override final;

			bool IsMinimized() const override final;
			void Minimize(bool _bMinimized) override final;

			bool IsMaximized() const override final;
			void Maximize(bool _bMaximized) override final;


			Flags<CursorMode> GetCursorMode() const override final;
			void SetCursorMode(Flags<CursorMode> _flags) override final;


			void SetWindowMode(WindowMode _mode) override final;

			void Create(const WindowCreateInfos& _infos) override final;
			void Destroy() override final;

			void Close() override final;
			bool ShouldClose() const override final;

#if SA_RENDER_VULKAN_IMPL

			VK::WindowSurfaceHandle VkCreateWindowSurfaceHandle(const VK::Instance& _instance) const override final;
			void VkDestroyWindowSurfaceHandle(const VK::Instance& _instance, VK::WindowSurfaceHandle _surfaceHandle) const override final;

#endif // SA_RENDER_VULKAN_IMPL

			/**
			*	\brief \e Getter of GLFW internal handle.
			* 
			*	\returns GLFW internal handle.
			*/
			GLFWwindow* GetHandle() const;
		};
	}
}


/** \} */

#endif // SAPPHIRE_WINDOWING_GLFW_WINDOW_GUARD
