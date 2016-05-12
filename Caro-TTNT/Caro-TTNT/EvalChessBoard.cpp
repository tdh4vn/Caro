#include "EvalChessBoard.h"



EvalChessBoard::EvalChessBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			eBoard[i][j] = NOT_PIE;
		}
	}
}


EvalChessBoard::~EvalChessBoard()
{
}

void EvalChessBoard::rsBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			eBoard[i][j] = NOT_PIE;
		}	
	}
	
}
Point EvalChessBoard::getPositionOfMaxPoint()
{
	int max = 0;
	Point p;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (eBoard[i][j] > max)
			{
				p.x = i;
				p.y = j;
				max = eBoard[i][j];
			}
		}
	}
	return p;
}