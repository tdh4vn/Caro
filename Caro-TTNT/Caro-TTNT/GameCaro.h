#pragma once
#include "EvalChessBoard.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "iostream"


using namespace sf;
using namespace std;

class GameCaro
{
private:

	bool fWin = false;
	int banco[20][20];
	int DScore[6];// = { 0, 1, 9, 81, 729, 1458 };
	int AScore[6];// = { 0, 2, 18, 162, 1458, 2916 };
	
	int maxDepth = 11, maxMove = 3, turnPlayer = 1, depth = 0, _x, _y, stage = 0, fEnd = 0;
	Point pos, PCMove[6], WinMove[13], PlayerMove[6];
	EvalChessBoard eBoard;
	Vector2i mouse_position;
	Texture tex_selectIcon, tex_bg, tex_X, tex_O, tex_cursor, tex_bg0, tex_sec0, tex_sec1, tex_sec2, tex_sec3, tex_sec4, tex_ovd, tex_P1, tex_P2, tex_vs, tex_back, tex_try, tex_seclection2, tex_win, tex_S3, tex_bgSta;
	Sprite spr_selectIcon, spr_bg, spr_x, spr_o, spr_cursor, spr_bg0, spr_sec0, spr_sec1, spr_sec2, spr_sec3, spr_sec4, spr_ovd, spr_P1, spr_P2, spr_vs, spr_back, spr_try, spr_seclection2, spr_win, spr_S3, spr_bgSta;
	Sprite sprCursor;
public:
	GameCaro();
	~GameCaro();
	void loadResource();
	int testWin(int cl, int rw);
	void eval(int player, EvalChessBoard& eBoard);
	void search();
	void AI();
	void run();

};

