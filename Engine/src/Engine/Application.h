#pragma once

#include "Core.h"
#include "Core.h"

namespace Sky
{
	class SKY_API Application
	{
	public:
		Application();
		virtual ~Application();
		virtual void Run();
	};

	Application* CreateApplication();
}