#include <iostream>
#include "windows.h"
#include "GameBoard.h"
#include <ctime>

int main()
{
	GameBoard gb;
	gb.printBoard();	
	
	std::srand(std::time(0));
	while (true)
	{
		if (0x8000 && GetAsyncKeyState(VK_UP))
		{			
			gb.shiftBoardUp();			
			gb.placeRandomValue();
			gb.printBoard();
		}
		else if (0x8000 && GetAsyncKeyState(VK_RIGHT))
		{
			gb.shiftBoardRight();			
			gb.placeRandomValue();
			gb.printBoard();
		}
		else if (0x8000 && GetAsyncKeyState(VK_LEFT))
		{
			gb.shiftBoardLeft();			
			gb.placeRandomValue();
			gb.printBoard();
		}
		else if (0x8000 && GetAsyncKeyState(VK_DOWN))
		{
			gb.shiftBoardDown();			
			gb.placeRandomValue();
			gb.printBoard();
		}
		else if (0x8000 && GetAsyncKeyState(0x51))//q-quit
		{
			break;
		}		

		Sleep(200);
	}
	return 0;
}