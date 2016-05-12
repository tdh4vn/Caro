#pragma once
#include "Constant.h"
class Point{
public:
	int x;
	int y;
};
class EvalChessBoard
{
public:
	
	int eBoard[BOARD_SIZE][BOARD_SIZE];
	EvalChessBoard();
	~EvalChessBoard();
	void rsBoard();
	Point getPositionOfMaxPoint();
};

