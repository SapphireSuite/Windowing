// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include "main_common.hpp"

#include <SA/Collections/Debug>
using namespace SA;

static ConsoleLogStream cslStream;
static FileLogStream fileStream;
static Logger logger;

void InitLogger()
{
	SA::Debug::logger = &logger;
	logger.Register(cslStream);
	logger.Register(fileStream);
}

void Init(AWindowInterface* _interface)
{
	_interface->Create();
}

void UnInit(AWindowInterface* _interface)
{
	_interface->Destroy();
}

int main_common(AWindowInterface* _interface, bool bInitLogger)
{
	if(bInitLogger)
		InitLogger();

	Init(_interface);
	UnInit(_interface);

	return 0;
}
