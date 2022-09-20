// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_WINDOWING_GLFW_INPUT_INTERFACE_GUARD
#define SAPPHIRE_WINDOWING_GLFW_INPUT_INTERFACE_GUARD

#include <SA/Windowing/Base/AInputInterface.hpp>

namespace SA
{
	namespace GLFW
	{
		class InputInterface : public AInputInterface
		{
		public:
			void Create() override final;
			void Destroy() override final;

			void Clear() override final;

			void Update() override final;
		};
	}
}

#endif // SAPPHIRE_WINDOWING_GLFW_INPUT_INTERFACE_GUARD
