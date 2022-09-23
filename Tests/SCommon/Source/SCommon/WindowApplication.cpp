// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include "WindowApplication.hpp"

namespace SA
{
	namespace SCommon
	{
		void WindowApplication::Init()
		{
			mWindow = mWindowIntf->CreateWindow();
		}

		void WindowApplication::UnInit()
		{
			mWindowIntf->DestroyWindow(mWindow);
		}

		void WindowApplication::Loop()
		{
			SA_LOG("Start Game loop.");

		#if !SA_CI

			while (!mWindow->ShouldClose())

		#endif
			{
				Update();
			}

			SA_LOG("End Game loop.");
		}

		void WindowApplication::Update()
		{
			mWindowIntf->GetInputInterface()->Update();
		}

		int WindowApplication::Run(AWindowInterface* _win_intf)
		{
			mWindowIntf = _win_intf;

			Init();

			Loop();

			UnInit();

			return 0;
		}
	}
}
