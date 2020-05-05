#include "pch.h"
#include "CppUnitTest.h"
#include "..\2048\GameBoard.h"
#include "shiftBoardUP_Ags.h"
#include "shiftBoardDown_Args.h"
#include "shiftBoardLeft_Args.h"
#include "shiftBoardRight_Args.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testframe
{
	TEST_CLASS(Testframe)
	{
	public:
		
		TEST_METHOD(ShiftBoardLeft)
		{
			GameBoard gb;
			wchar_t message[12];

			for (int i = 0; i < boardLeft_STEPS_COUNT; i++)
			{
				for (int j = 0; j < 4; j++)
					for (int k = 0; k < 4; k++)
						gb.placeValue(k, j, boardLeft_initialGbStates[i][j][k]);

				gb.shiftBoardLeft();

				swprintf(message, 20, L"step = %d", i);
				Assert::AreEqual<int>(0, memcmp(gb.getGameBoard(), boardLeft_expectedGbStates[i], sizeof(boardLeft_expectedGbStates[i])), message);
			}
		}
		
		TEST_METHOD(ShiftBoardRight)
		{
			GameBoard gb;
			wchar_t message[12];

			for (int i = 0; i < boardRight_STEPS_COUNT; i++)
			{
				for (int j = 0; j < 4; j++)
					for (int k = 0; k < 4; k++)
						gb.placeValue(k, j, boardRight_initialGbStates[i][j][k]);

				gb.shiftBoardRight();

				swprintf(message, 20, L"step = %d", i);
				Assert::AreEqual<int>(0, memcmp(gb.getGameBoard(), boardRight_expectedGbStates[i], sizeof(boardRight_expectedGbStates[i])), message);
			}
		}
		
		TEST_METHOD(ShiftBoardUp)
		{
			GameBoard gb;
			wchar_t message[12];

			for (int i = 0; i < boardUp_STEPS_COUNT; i++)
			{
				for (int j = 0; j < 4; j++)
					for (int k = 0; k < 4; k++)
						gb.placeValue(k, j, boardUp_initialGbStates[i][j][k]);				
				
				gb.shiftBoardUp();

				swprintf(message, 20, L"step = %d", i);
				Assert::AreEqual<int>(0, memcmp(gb.getGameBoard(), boardUp_expectedGbStates[i], sizeof(boardUp_expectedGbStates[i])), message);
			}
		}
		
		TEST_METHOD(ShiftBoardDown)
		{
			GameBoard gb;
			wchar_t message[12];

			for (int i = 0; i < boardDown_STEPS_COUNT; i++)
			{
				for (int j = 0; j < 4; j++)
					for (int k = 0; k < 4; k++)
						gb.placeValue(k, j, boardDown_initialGbStates[i][j][k]);
				
				gb.shiftBoardDown();

				swprintf(message, 20, L"step = %d", i);
				Assert::AreEqual<int>(0, memcmp(gb.getGameBoard(), boardDown_expectedGbStates[i], sizeof(boardDown_expectedGbStates[i])), message);
			}
		}
	};
}
