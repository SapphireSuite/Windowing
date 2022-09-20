// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <main_common.hpp>

#include <SA/Collections/Debug>
using namespace SA;

#if SA_WINDOWING_GLFW

	#include <SA/Windowing/GLFW/GLFWWindowInterface.hpp>

#endif // SA_WINDOWING_GLFW

#define MULTITHREAD_OPT 1

#if MULTITHREAD_OPT

#include <list>
#include <thread>

std::list<std::thread> threads;
LoggerThread logger;

#define SA_WINDOWING_THREAD_BEGIN(_renderInterfaceT) threads.emplace_back(std::thread([](){
#define SA_WINDOWING_THREAD_END() }));

#else

#define SA_WINDOWING_THREAD_BEGIN(_renderInterfaceT) SA_LOG()
#define SA_WINDOWING_THREAD_END()

#endif

template <typename WindowInterfaceT>
void main_windowing()
{
	SA_WINDOWING_THREAD_BEGIN(WindowInterfaceT)

	WindowInterfaceT interface;
	main_common(&interface, !MULTITHREAD_OPT);

	SA_WINDOWING_THREAD_END()
}

int main()
{
#if MULTITHREAD_OPT

	SA::Debug::logger = &logger;

	ConsoleLogStream cslStream;
	logger.Register(cslStream);

	FileLogStream fileStream;
	logger.Register(fileStream);

#endif // MULTITHREAD_OPT


#if SA_WINDOWING_GLFW

	main_render<GLFW::WindowInterface>();

#endif // SA_WINDOWING_GLFW


#if MULTITHREAD_OPT

	// Join all.

	for(auto& _thread : threads)
	{
		if(_thread.joinable())
			_thread.join();
	}

	logger.Flush();

#endif // MULTITHREAD_OPT

	return 0;
}
