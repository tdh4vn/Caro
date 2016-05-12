#pragma once
#include "Scene.h"
#include "SFML\Graphics.hpp"
#include "Constant.h"
#include "EvalChessBoard.h"
class PlayerVsPlayerScene :
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
	int turnPlayer = 1;
	int fEnd = 0;
	Point pos;
	int mBoard[BOARD_SIZE][BOARD_SIZE];
public:
	PlayerVsPlayerScene();
	~PlayerVsPlayerScene();
	void loadSprite();
	int testWin(int cl, int rw);
	void draw(sf::RenderWindow &renderWindow);
	void update(sf::RenderWindow &renderWindow);
	void onMouseClick(sf::Vector2i mousePositon);
};