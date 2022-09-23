// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include "WindowApplication.hpp"

namespace SA
{
	namespace SCommon
	{
		void WindowApplication::Init(AWindowInterface* _win_intf)
		{
			mWindow = _win_intf->CreateWindow();
		}

		void WindowApplication::UnInit(AWindowInterface* _win_intf)
		{
			_win_intf->DestroyWindow(mWindow);
		}

		void WindowApplication::Loop(AWindowInterface* _win_intf)
		{
			SA_LOG("Start Game loop.");

		#if !SA_CI

			while (!mWindow->ShouldClose())

		#endif
			{
				Update(_win_intf);
			}

			SA_LOG("End Game loop.");
		}

		void WindowApplication::Update(AWindowInterface* _win_intf)
		{
			_win_intf->GetInputInterface()->Update();
		}

		int WindowApplication::Run(AWindowInterface* _win_intf)
		{
			Init(_win_intf);

			Loop(_win_intf);

			UnInit(_win_intf);

			return 0;
		}
	}
}
