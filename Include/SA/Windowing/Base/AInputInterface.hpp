// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_WINDOWING_AINPUT_INTERFACE_GUARD
#define SAPPHIRE_WINDOWING_AINPUT_INTERFACE_GUARD

#include <SA/HI/Interface.hpp>

namespace SA
{
	class AInputInterface : private HI::Interface
	{
	public:
		void Create() override;
		void Destroy() override;

		void Clear() override;

		virtual void Update() = 0;

		// virtual AInputWindowContext* CreateInputWindowContext(AWindow* _win) = 0;
		// virtual void DestroyInputWindowContext(AInputWindowContext* _winContext) = 0;
	};
}

#endif // SAPPHIRE_WINDOWING_AINPUT_INTERFACE_GUARD
