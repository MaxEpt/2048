#pragma once
class GameBoard
{
public:
	GameBoard();
	~GameBoard();
	
	/**
	 * Prints current board array to console
	 * @return void
	*/
	void printBoard();

	/**
	 * Shifts gameboard left
	 * @return void
	*/
	void shiftBoardLeft();

	/**
	 * Shifts gameboard right
	 * @return void
	*/
	void shiftBoardRight();
	
	/**
	 * Shifts gameboard up
	 * @return void
	*/
	void shiftBoardUp();
	
	/**
	 * Shifts gameboard down
	 * @return void
	*/
	void shiftBoardDown();
	
	/**
	 * Tries to place new random value on gameboard
	 * @return void
	*/
	void placeRandomValue();
	
	/**
	 * Checks was gameboard shifted to any side
	 * @return bool
	*/
	bool isBoardShifted();

private:
	unsigned int m_aBoard[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	bool m_isBoardShifted = false;

	/**
	 * Checks can new value be placed on given coordinates
	 * @return bool
	*/
	bool canPlaceValue(unsigned int x, unsigned int y);	
};

