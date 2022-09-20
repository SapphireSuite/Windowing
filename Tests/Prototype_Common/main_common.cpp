// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include "main_common.hpp"

#include <SA/Collections/Debug>
#include <SA/Collections/Windowing>
using namespace SA;

static ConsoleLogStream cslStream;
static FileLogStream fileStream;
static Logger logger;

AWindow* window = nullptr;

void InitLogger()
{
	SA::Debug::logger = &logger;
	logger.Register(cslStream);
	logger.Register(fileStream);
}

void Init(AWindowInterface* _interface)
{
	_interface->Create();
	window = _interface->CreateWindow();
}

void UnInit(AWindowInterface* _interface)
{
	_interface->DestroyWindow(window);
	_interface->Destroy();
}

int main_common(AWindowInterface* _interface, bool bInitLogger)
{
	if(bInitLogger)
		InitLogger();

	Init(_interface);

//{ Loop

	SA_LOG("Start Game loop.");


#if !SA_CI

	//while (!window->ShouldClose())

#endif
	{
	}


	SA_LOG("End Game loop.");

//}



	UnInit(_interface);

	return 0;
}
