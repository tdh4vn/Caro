#pragma once
#include "Scene.h"
#include "EvalChessBoard.h"
#include "Constant.h"
class PlayVsComputerScene :
	public Scene
{
private:
	sf::Texture texBackground;
	sf::Sprite sprBackground;
	sf::Texture texBoard;
	sf::Sprite sprBoard;
	sf::Texture texPieX;
	sf::Sprite sprPieX;
	sf::Texture texPieO;
	sf::Sprite sprPieO;
	sf::Texture texAvaX;
	sf::Sprite sprAvaX;
	sf::Texture texAvaO;
	sf::Sprite sprAvaO;
	sf::Texture texLastPosition;
	sf::Sprite sprLastPosition;
	sf::Texture texBtnTry;
	sf::Sprite sprBtnTry;
	sf::Texture texBack;
	sf::Sprite sprBack;
	sf::Texture texWin;
	sf::Sprite sprWin;
	sf::Texture texSelect;
	sf::Sprite sprSelect;

	int mBoard[BOARD_SIZE][BOARD_SIZE];
	int DScore[6];// = { 0, 1, 9, 81, 729, 1458 };
	int AScore[6];// = { 0, 2, 18, 162, 1458, 2916 };
	EvalChessBoard evalChessBoard;
	bool fWin;
	int maxDepth = 11, maxMove = 3, turnPlayer = 1, depth = 0, _x, _y, fEnd = 0;
	Point pos, PCMove[6], WinMove[13], PlayerMove[6];
public:
	PlayVsComputerScene();
	~PlayVsComputerScene();
	void loadSprite();
	void draw(sf::RenderWindow &renderWindow);
	void update(sf::RenderWindow &renderWindow);
	void onMouseClick(sf::Vector2i mousePositon);
	int testWin(int cl, int rw);
	void eval(int player, EvalChessBoard& eBoard);
	void search();
	void AI();
};

