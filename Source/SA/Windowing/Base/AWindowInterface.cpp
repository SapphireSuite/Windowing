// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include "AWindowInterface.hpp"

namespace SA
{
	void AWindowInterface::Create()
	{
		HI::Interface::Create();
	}

	void AWindowInterface::Destroy()
	{
		HI::Interface::Destroy();
	}

	void AWindowInterface::Clear()
	{
		HI::Interface::Clear();
	}

#if SA_RENDER_VULKAN_IMPL

	bool AWindowInterface::VkQueryRequiredExtensions(std::vector<const char*>& _extensions) const
	{
		(void)_extensions;

		return true;
	}

#endif
}
