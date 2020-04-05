#include <iostream>
#include "windows.h"

int main()
{	
	while (true)
	{
		if (0x8000 && GetAsyncKeyState(VK_UP))
		{
			std::cout << "UP" << std::endl;
		}
		else if (0x8000 && GetAsyncKeyState(VK_RIGHT))
		{
			std::cout << "RIGHT" << std::endl;
		}
		else if (0x8000 && GetAsyncKeyState(VK_LEFT))
		{
			std::cout << "LEFT" << std::endl;
		}
		else if (0x8000 && GetAsyncKeyState(VK_DOWN))
		{
			std::cout << "DOWN" << std::endl;
		}
		else if (0x8000 && GetAsyncKeyState(0x51))//q-quit
		{
			break;
		}
		else
		{			
		}
		
		Sleep(100);
	}
	return 0;
}