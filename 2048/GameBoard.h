#pragma once
class GameBoard
{
public:
	GameBoard();
	~GameBoard();
	
	/**
	 * Prints current board array to console
	 * @param none
	 * @return void
	*/
	void printBoard();

	/**
	 * Shifts gameboard left
	 * @param none
	 * @return void
	*/
	void shiftBoardLeft();

	/**
	 * Shifts gameboard right
	 * @param none
	 * @return void
	*/
	void shiftBoardRight();
	
	/**
	 * Shifts gameboard up
	 * @param none
	 * @return void
	*/
	void shiftBoardUp();
	
	/**
	 * Shifts gameboard down
	 * @param none
	 * @return void
	*/
	void shiftBoardDown();
	
	/**
	 * Tries to place new random value on gameboard
	 * @param none
	 * @return void
	*/
	void placeRandomValue();

	/**
	 * Places given value on given coordinates
	 * @param unsigned int x coordinate of needed column
	 * @param unsigned int y coordinate of needed row
	 * @return bool true if given value was placed 
	*/
	bool placeValue(unsigned int x, unsigned int y, unsigned int value);

	/**
	 * Returns pointer to game board array
	 * @param none	 
	 * @return unsigned int* 
	*/
	unsigned int (*getGameBoard())[4];

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

