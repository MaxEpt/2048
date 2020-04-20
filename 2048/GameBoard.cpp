#include "GameBoard.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

GameBoard::GameBoard()
{	
	placeRandomValue();
}

GameBoard::~GameBoard()
{
}

void GameBoard::printBoard()
{
	system("cls");
	/*
	Print table head
	*/
	std::cout << char(218);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 9; j++)
			std::cout << char(196);
		if (i == 3)
		{
			std::cout << char(191);
		}
		else
		{
			std::cout << char(194);
		}
	}
	std::cout << std::endl;
	/*
		End print table head
	*/

	for (int ati = 0; ati < 4; ati++)
	{
		std::cout << char(179);

		for (int atj = 0; atj < 4; atj++)
		{
			std::string strTileNum;

			if (m_aBoard[ati][atj] == 0)
			{
				strTileNum = ' ';
			}
			else
			{
				strTileNum = std::to_string(m_aBoard[ati][atj]);
			}

			int spacesBefore = (9 - strTileNum.length()) / 2;
			int spacesAfter = (9 - strTileNum.length()) % 2;
			if (spacesAfter == 0)
			{
				spacesAfter = spacesBefore;
			}
			else
			{
				spacesAfter += spacesBefore;
			}
			spacesAfter += 1;
			spacesBefore += strTileNum.length();
			std::cout << std::setfill(' ') << std::setw(spacesBefore)
				<< strTileNum
				<< std::setw(spacesAfter)
				<< char(179);

		}
		std::cout << std::endl;


		if (ati == 3)
		{
			std::cout << char(192);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 9; j++)
					std::cout << char(196);

				if (i == 3)
					std::cout << char(217);//
				else
					std::cout << char(193);//193
			}
		}
		else
		{
			std::cout << char(195);//192
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 9; j++)
					std::cout << char(196);

				if (i == 3)
					std::cout << char(180);//
				else
					std::cout << char(197);//193
			}
		}

		std::cout << std::endl;
	}
}

void GameBoard::shiftBoardLeft()
{
	int lastIndex = 0;
	int j = 0;
	for (int i = 0; i < 4; i++)
	{
		if (m_aBoard[i][0] == 0)
			lastIndex = 0;
		else
			lastIndex = 1;

		j = 1;
		while (j < 4)
		{
			if (m_aBoard[i][j] == 0)
			{
				j++;
				continue;
			}
			else
			{
				if (m_aBoard[i][j] == m_aBoard[i][lastIndex - 1])
				{
					m_aBoard[i][lastIndex - 1] += m_aBoard[i][j];
					m_aBoard[i][j] = 0;
					lastIndex = j;
				}
				else if (m_aBoard[i][lastIndex] == 0)
				{
					m_aBoard[i][lastIndex] = m_aBoard[i][j];
					m_aBoard[i][j] = 0;
					lastIndex = j;
				}
				else
				{
					j++;
					lastIndex = j;
					continue;
				}
				j++;
			}
		}
	}
}

void GameBoard::shiftBoardRight()
{
	int lastIndex = 0;
	int j = 0;
	for (int i = 0; i < 4; i++)
	{
		if (m_aBoard[i][3] == 0)
			lastIndex = 3;
		else
			lastIndex = 2;

		j = 2;
		while (j >= 0)
		{
			if (m_aBoard[i][j] == 0)
			{
				j--;
				continue;
			}
			else
			{
				if (m_aBoard[i][j] == m_aBoard[i][lastIndex + 1])
				{
					m_aBoard[i][lastIndex + 1] += m_aBoard[i][j];
					m_aBoard[i][j] = 0;
					lastIndex = j;
				}
				else if (m_aBoard[i][lastIndex] == 0)
				{
					m_aBoard[i][lastIndex] = m_aBoard[i][j];
					m_aBoard[i][j] = 0;
					lastIndex = j;
				}
				else
				{
					j--;
					lastIndex = j;
					continue;
				}
				j--;
			}
		}
	}
}

void GameBoard::shiftBoardUp()
{
	int lastIndex = 0;
	int j = 0;
	for (int i = 0; i < 4; i++)
	{
		if (m_aBoard[0][i] == 0)
			lastIndex = 0;
		else
			lastIndex = 1;

		j = 1;
		while (j < 4)
		{
			if (m_aBoard[j][i] == 0)
			{
				j++;
				continue;
			}
			else
			{
				if (m_aBoard[j][i] == m_aBoard[lastIndex - 1][i])
				{
					m_aBoard[lastIndex - 1][i] += m_aBoard[j][i];
					m_aBoard[j][i] = 0;
					lastIndex = j;
				}
				else if (m_aBoard[lastIndex][i] == 0)
				{
					m_aBoard[lastIndex][i] = m_aBoard[j][i];
					m_aBoard[j][i] = 0;
					lastIndex = j;
				}
				else
				{
					j++;
					lastIndex = j;
					continue;
				}
				j++;
			}
		}
	}
}

void GameBoard::shiftBoardDown()
{
	int lastIndex = 0;
	int j = 0;
	for (int i = 0; i < 4; i++)
	{
		if (m_aBoard[3][i] == 0)
			lastIndex = 3;
		else
			lastIndex = 2;

		j = 2;
		while (j >= 0)
		{
			if (m_aBoard[j][i] == 0)
			{
				j--;
				continue;
			}
			else
			{
				if (m_aBoard[j][i] == m_aBoard[lastIndex + 1][i])
				{
					m_aBoard[lastIndex + 1][i] += m_aBoard[j][i];
					m_aBoard[j][i] = 0;
					lastIndex = j;
				}
				else if (m_aBoard[lastIndex][i] == 0)
				{
					m_aBoard[lastIndex][i] = m_aBoard[j][i];
					m_aBoard[j][i] = 0;
					lastIndex = j;
				}
				else
				{
					j--;
					lastIndex = j;
					continue;
				}
				j--;
			}
		}
	}
}

bool GameBoard::canPlaceValue(unsigned int x, unsigned int y)
{	
	if(x>3 || y>3)
		return false;

	if (m_aBoard[y][x] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameBoard::placeRandomValue()
{	
	
	unsigned int x = std::rand() % 3;
	unsigned int y = std::rand() % 3;
	unsigned int new_value = 0;
	if (canPlaceValue(x, y))
	{
		m_aBoard[y][x] = 2;		
	}
	else
	{
		placeRandomValue();
	}
}

bool GameBoard::isBoardShifted()
{
	return m_isBoardShifted;
}
