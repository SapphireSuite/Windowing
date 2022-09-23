// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_WINDOWING_SCOMMON_WINDOW_APPLICATION_GUARD
#define SAPPHIRE_WINDOWING_SCOMMON_WINDOW_APPLICATION_GUARD

#include <SA/Windowing/Base/AWindow.hpp>
#include <SA/Windowing/Base/AWindowInterface.hpp>

#include "SelectedWindowInterface.hpp"

namespace SA
{
	namespace SCommon
	{
		class WindowApplication
		{
		protected:
			//AWindowInterface* mWindowIntf = nullptr;
			AWindow* mWindow = nullptr;

			virtual void Init(AWindowInterface* _win_intf);
			virtual void UnInit(AWindowInterface* _win_intf);

			virtual void Loop(AWindowInterface* _win_intf);
			virtual void Update(AWindowInterface* _win_intf);

		public:
			template <typename WindowInterfaceT = SelectedWindowInterface>
			int CreateAndRun()
			{
				WindowInterfaceT win_intf;

				win_intf.Create();

				const int res = Run(&win_intf);

				win_intf.Destroy();

				return res;
			}

			int Run(AWindowInterface* _win_intf);
		};
	}
}

#endif // SAPPHIRE_WINDOWING_SCOMMON_WINDOW_APPLICATION_GUARD
