// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include "AWindow.hpp"

namespace SA
{
	WindowMode AWindow::GetWindowMode() const
	{
		return mWindowMode;
	}

	void AWindow::Create(const WindowCreateInfos& _infos)
	{
		HI::Object::Create();

		(void)_infos;
	}

	void AWindow::Destroy()
	{
		HI::Object::Destroy();
	}
}
