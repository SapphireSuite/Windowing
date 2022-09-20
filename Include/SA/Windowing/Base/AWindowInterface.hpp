// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_WINDOWING_AWINDOW_INTERFACE_GUARD
#define SAPPHIRE_WINDOWING_AWINDOW_INTERFACE_GUARD

namespace SA
{
	class AWindowInterface
	{
	public:
		virtual ~AWindowInterface() = default;

		virtual void Create() = 0;
		virtual void Destroy() = 0;
	};
}

#endif // SAPPHIRE_WINDOWING_AWINDOW_INTERFACE_GUARD
