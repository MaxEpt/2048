#include "pch.h"
#include "CppUnitTest.h"
#include "..\2048\GameBoard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testframe
{
	TEST_CLASS(Testframe)
	{
	public:
		
		TEST_METHOD(ShiftBoardLeft)
		{
		}
		
		TEST_METHOD(ShiftBoardRight)
		{
		}
		
		TEST_METHOD(ShiftBoardUp)
		{
			GameBoard gb;

			gb.placeValue(0, 0, 2);
			gb.placeValue(0, 3, 2);

			gb.shiftBoardUp();
			
			unsigned int aExpectedBoard[4][4] =
			{
				{4,0,0,0},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0},
			};

			Assert::AreEqual<int>(0, memcmp(gb.getGameBoard(), aExpectedBoard, 16));
		}
		
		TEST_METHOD(ShiftBoardDown)
		{
		}
	};
}
