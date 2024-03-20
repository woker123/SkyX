#pragma once
#include "Application.h"

#ifdef SKY_PLATFORM_WINDOWS
extern Sky::Application* Sky::CreateApplication();

int main(int argc, char** argv)
{
	Sky::Application* app = Sky::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif
