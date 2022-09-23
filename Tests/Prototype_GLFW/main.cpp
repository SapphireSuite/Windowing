// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Collections/Debug>
using namespace SA;

#include <SCommon/WindowApplication.hpp>

int main()
{
	SA::Debug::InitDefaultLogger();

	SCommon::WindowApplication app;

	return app.CreateAndRun<GLFW::WindowInterface>();
}
