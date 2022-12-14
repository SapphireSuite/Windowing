// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_WINDOWING_AWINDOW_INTERFACE_GUARD
#define SAPPHIRE_WINDOWING_AWINDOW_INTERFACE_GUARD

#include <SA/HI/Interface.hpp>

#include "AWindow.hpp"
#include "AInputInterface.hpp"

namespace SA
{
	class AWindowInterface : private HI::Interface
	{
	protected:
		using HI::Interface::CheckCreated;

	public:
		void Create() override;
		void Destroy() override;

		void Clear() override;

		virtual AInputInterface* GetInputInterface() = 0;

		/**
		*	Create window with interface implementation.
		* 
		*	\param[in] _infos	Create infos
		* 
		*	\return Created window.
		*/
		virtual AWindow* CreateWindow(const WindowCreateInfos& _infos = WindowCreateInfos()) = 0;

		/**
		*	\brief Destroy window from interface.
		*	Window must have been created from this interface.
		* 
		*	\param[in] _window	Window to destroy.
		*/
		virtual void DestroyWindow(AWindow* _window) = 0;

	#if SA_RENDER_VULKAN_IMPL

		virtual bool VkQueryRequiredExtensions(std::vector<const char*>& _extensions) const;

	#endif
	};
}

#endif // SAPPHIRE_WINDOWING_AWINDOW_INTERFACE_GUARD
