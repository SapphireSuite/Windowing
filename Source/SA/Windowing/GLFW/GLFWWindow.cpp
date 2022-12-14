// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include "GLFWWindow.hpp"

#include "GLFWAPI.hpp"

#if SA_RENDER_VULKAN_IMPL

#include <SA/Render/Vulkan/VkInstance.hpp>

#endif

namespace SA
{
	namespace GLFW
	{
		Vec2ui Window::GetSize() const
		{
			Vec2i size;

			glfwGetWindowSize(mHandle, &size.x, &size.y);

			return size;
		}

		void Window::SetSize(const Vec2ui& _size)
		{
			(void)_size;
			// TODO:
			//mSavedSize = _size;

			//SetWindowMode(GetWindowMode());
		}


		Vec2ui Window::GetPosition() const
		{
			Vec2i pos;

			glfwGetWindowPos(mHandle, &pos.x, &pos.y);

			return pos;
		}

		void Window::SetPosition(const Vec2ui& _size)
		{
			glfwSetWindowPos(mHandle, _size.x, _size.y);
		}


		bool Window::IsMinimized() const
		{
			return glfwGetWindowAttrib(mHandle, GLFW_ICONIFIED);
		}

		void Window::Minimize(bool _bMinimized)
		{
			if (_bMinimized)
				glfwIconifyWindow(mHandle);
			else
				glfwRestoreWindow(mHandle);
		}


		bool Window::IsMaximized() const
		{
			return glfwGetWindowAttrib(mHandle, GLFW_MAXIMIZED);
		}

		void Window::Maximize(bool _bMaximized)
		{
			if (_bMaximized)
				glfwMaximizeWindow(mHandle);
			else
				glfwRestoreWindow(mHandle);
		}


		Flags<CursorMode> Window::GetCursorMode() const
		{
			Flags<CursorMode> flags;

			int inputMode = glfwGetInputMode(mHandle, GLFW_CURSOR);

			switch (inputMode)
			{
				case GLFW_CURSOR_DISABLED:
					flags = CursorMode::Hidden | CursorMode::Capture;
					break;
				case GLFW_CURSOR_HIDDEN:
					flags = CursorMode::Hidden;
					break;
				case GLFW_CURSOR_NORMAL:
					flags = CursorMode::None;
					break;
				default:
					SA_LOG(L"InputMode [" << inputMode << "] not supported yet!", Warning, SA/Windowing/GLFW);
					break;
			}

			return flags;
		}

		void Window::SetCursorMode(Flags<CursorMode> _flags)
		{
			if (_flags & CursorMode::Hidden)
			{
				if (_flags & CursorMode::Capture)
					glfwSetInputMode(mHandle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
				else
					glfwSetInputMode(mHandle, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
			}
			else if (_flags & CursorMode::Capture)
			{
				// TODO: Implement
			}
			else
				glfwSetInputMode(mHandle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

			onCursorModeChange(_flags);
		}


		void Window::SetWindowMode(WindowMode _mode)
		{
			if (_mode == mWindowMode)
				return;

			GLFWmonitor* const currMonitor = GetCurrentMonitor();
			const GLFWvidmode* const mode = glfwGetVideoMode(currMonitor);
			const Vec2i newSize = Vec2i{ mode->width, mode->height };


			// Previous mode was windowed: save values.
			if (mWindowMode == WindowMode::Windowed)
			{
				mSavedSize = GetSize();
				mSavedPosition = GetPosition();
			}


			switch (_mode)
			{
				case WindowMode::Windowed:
				{
					glfwSetWindowMonitor(mHandle, nullptr, mSavedPosition.x, mSavedPosition.y, mSavedSize.x, mSavedSize.y, 0);
					break;
				}
				case WindowMode::FullScreen:
				{
					glfwSetWindowMonitor(mHandle, currMonitor, 0, 0, newSize.x, newSize.y, mode->refreshRate);
					break;
				}
				case WindowMode::Borderless:
				{
					// Full screen before.
					if (mWindowMode == WindowMode::FullScreen)
					{
						// Ensure correct desktop resolution.
						// Source: https://www.glfw.org/docs/3.3/window_guide.html#window_windowed_full_screen

						SetWindowMode(WindowMode::Windowed);
						SetWindowMode(WindowMode::Borderless);
					}
					else
						glfwSetWindowMonitor(mHandle, nullptr, 0, 0, newSize.x, newSize.y, mode->refreshRate);

					break;
				}
				default:
				{
					SA_LOG(L"WindowMode [" << _mode << "] not supported yet!", Warning, SA/Windowing/GLFW);
					break;
				}
			}

			mWindowMode = _mode;
			onWindowModeChange(_mode);
		}


		void Window::Create(const WindowCreateInfos& _infos)
		{
			AWindow::Create(_infos);

			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
			mHandle = glfwCreateWindow(_infos.dimension.x, _infos.dimension.y, _infos.name.c_str(), nullptr, nullptr);

			SA_ASSERT(Default, SA/Windowing/GLFW, mHandle, L"GLFW create window failed!");

			glfwSetWindowPos(mHandle, _infos.position.x, _infos.position.y);

			glfwSetWindowUserPointer(mHandle, this);
			glfwSetWindowSizeCallback(mHandle, ResizeCallback);
			glfwSetWindowIconifyCallback(mHandle, MinimizedCallback);
			glfwSetWindowMaximizeCallback(mHandle, MaximizedCallback);

			SetCursorMode(_infos.cursorMode);
			SetWindowMode(_infos.windowMode);
			

			if (_infos.bMaximized)
				Maximize(true);

			if (_infos.bMinimized)
				Minimize(true);

			SA_LOG(L"Window created.", Infos, SA/Windowing/GLFW);
		}

		void Window::Destroy()
		{
			SA_ASSERT(Nullptr, SA/Windowing/GLFW, mHandle, L"Try to destroy a non-created window, call Create() first.");

			glfwDestroyWindow(mHandle);
			mHandle = nullptr;

			AWindow::Destroy();

			SA_LOG(L"Window destroyed.", Infos, SA/Windowing/GLFW);
		}


		void Window::Close()
		{
			glfwSetWindowShouldClose(mHandle, GLFW_TRUE);
		}

		bool Window::ShouldClose() const
		{
			return glfwWindowShouldClose(mHandle);
		}


		void Window::MinimizedCallback(GLFWwindow* _handle, int32_t _minimized)
		{
			GLFW::Window* const win = static_cast<GLFW::Window*>(glfwGetWindowUserPointer(_handle));
			SA_ASSERT(Nullptr, SA/Windowing/GLFW, win);

			win->onMinimized(_minimized);
		}

		void Window::MaximizedCallback(GLFWwindow* _handle, int32_t _maximized)
		{
			GLFW::Window* const win = static_cast<GLFW::Window*>(glfwGetWindowUserPointer(_handle));
			SA_ASSERT(Nullptr, SA/Windowing/GLFW, win);

			win->onMaximized(_maximized);
		}

		void Window::ResizeCallback(GLFWwindow* _handle, int32_t _width, int32_t _height)
		{
			GLFW::Window* const win = static_cast<GLFW::Window*>(glfwGetWindowUserPointer(_handle));
			SA_ASSERT(Nullptr, SA/Windowing/GLFW, win);

			Vec2ui newSize = Vec2i{ _width, _height };

			// Window minimized (in/out).
			if (win->IsMinimized() || newSize == win->GetSize())
				return;

			win->onResize(newSize);
		}


		GLFWmonitor* Window::GetCurrentMonitor() const
		{
			// Source: https://stackoverflow.com/questions/21421074/how-to-create-a-full-screen-window-on-the-current-monitor-with-glfw

			Vec2i winPos;
			glfwGetWindowPos(mHandle, &winPos.x, &winPos.y);

			const Vec2i winSize = GetSize();

			int32_t num = 0;
			int32_t bestOverlap = 0;
			GLFWmonitor* const* const monitors = glfwGetMonitors(&num);
			GLFWmonitor* bestMonitor = glfwGetPrimaryMonitor();

			for (int32_t i = 0u; i < num; ++i)
			{
				Vec2i monPos;
				glfwGetMonitorPos(monitors[i], &monPos.x, &monPos.y);

				const GLFWvidmode* const mode = glfwGetVideoMode(monitors[i]);

				const int32_t overlap = std::max(0, std::min(winPos.x + winSize.x, monPos.x + mode->width) - std::max(winPos.x, monPos.x));

				if (overlap > bestOverlap)
				{
					bestOverlap = overlap;
					bestMonitor = monitors[i];
				}
			}

			return bestMonitor;
		}

#if SA_RENDER_VULKAN_IMPL

		VK::WindowSurfaceHandle Window::VkCreateWindowSurfaceHandle(const VK::Instance& _instance) const
		{
			CheckCreated();

			VK::WindowSurfaceHandle vkSurface = VK_NULL_HANDLE;

			SA_VK_ASSERT(glfwCreateWindowSurface(_instance, mHandle, nullptr, &vkSurface), L"Failed to create VkRenderSurface from GLFW window!");

			SA_LOG(L"Window Surface Handle [" << vkSurface << L"] created.", Infos, SA/Windowing/GLFW);

			return vkSurface;
		}

		void Window::VkDestroyWindowSurfaceHandle(const VK::Instance& _instance, VK::WindowSurfaceHandle _surfaceHandle) const
		{
			CheckCreated();

			vkDestroySurfaceKHR(_instance, _surfaceHandle, nullptr);

			SA_LOG(L"Window Surface Handle [" << _surfaceHandle << L"] destroyed.", Infos, SA/Windowing/GLFW);
		}

#endif // SA_RENDER_VULKAN_IMPL

		GLFWwindow* Window::GetHandle() const
		{
			return mHandle;
		}
	}
}
