// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Collections/Debug>
using namespace SA;

#include <SCommon/WindowApplication.hpp>

class SampleApp : public SCommon::WindowApplication
{
protected:
	void Init() override final
	{
		SCommon::WindowApplication::Init();
	}

	void UnInit() override final
	{
		SCommon::WindowApplication::UnInit();
	}

	void Loop() override final
	{
		SCommon::WindowApplication::Loop();
	}

	void Update() override final
	{
		SCommon::WindowApplication::Update();
	}
};

int main()
{
	SA::Debug::InitDefaultLogger();

	SampleApp app;

	return app.CreateAndRun<GLFW::WindowInterface>();
}
