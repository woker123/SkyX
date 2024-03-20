#include "Engine.h"

class SandBoxApp : public Sky::Application
{
public:
	virtual void Run()
	{
		Application::Run();

	}
};

Sky::Application* Sky::CreateApplication()
{
	return new SandBoxApp();
}