#include <iostream>


namespace SkyX
{
	__declspec(dllexport) void Print()
	{
		std::cout << "Hello SkyX Engine!" << std::endl;
	}
}
