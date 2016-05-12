#include "PlayerVsPlayerScene.h"
#include "ImageDirection.h"
#include "GameManager.h"


PlayerVsPlayerScene::PlayerVsPlayerScene()
{
	loadSprite();
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			mBoard[i][j] = NOT_PIE;
		}
	}
}

void PlayerVsPlayerScene::loadSprite()
{
	texBackground.loadFromFile(SPR_BG_MAIN);
	sprBackground.setTexture(texBackground);
	texBoard.loadFromFile(SPR_BG_BOARD);
	sprBoard.setTexture(texBoard);
	texPieX.loadFromFile(SPR_X);
	sprPieX.setTexture(texPieX);
	texPieO.loadFromFile(SPR_O);
	sprPieO.setTexture(texPieO);
	texAvaX.loadFromFile(SPR_AVATAR_X);
	sprAvaX.setTexture(texAvaX);
	texAvaO.loadFromFile(SPR_AVATAR_O);
	sprAvaO.setTexture(texAvaO);

	texLastPosition.loadFromFile(SPR_LAST_POSTION);
	sprLastPosition.setTexture(texLastPosition);
	texBtnTry.loadFromFile(SPR_BUTTON_REPLAY);
	sprBtnTry.setTexture(texBtnTry);
	texBack.loadFromFile(SPR_BUTTON_BACK);
	sprBack.setTexture(texBack);
	texWin.loadFromFile(SPR_WIN);
	sprWin.setTexture(texWin);
	texSelect.loadFromFile(SPR_SELECT_ICON);
	sprSelect.setTexture(texSelect);
	sprLastPosition.setPosition(-100, -100);
	sprAvaX.setPosition(15, 100);
	sprAvaO.setPosition(665, 100);
	sprBtnTry.setPosition(50, 550);
	sprBack.setPosition(700, 550);
	sprSelect.setPosition(-4999, -4999);
	sprWin.setPosition(-4999, -4999);
	sprBoard.setPosition(150, 100);
}


PlayerVsPlayerScene::~PlayerVsPlayerScene()
{
}
void PlayerVsPlayerScene::draw(sf::RenderWindow &renderWindow)
{
	renderWindow.draw(sprBackground);
	renderWindow.draw(sprBoard);
	renderWindow.draw(sprAvaX);
	renderWindow.draw(sprAvaO);
	renderWindow.draw(sprBtnTry);
	renderWindow.draw(sprBack);
	renderWindow.draw(sprBoard);
	renderWindow.draw(sprLastPosition);
	renderWindow.draw(sprWin);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (mBoard[i][j] == TURN_COM)
			{
				sprPieO.setPosition(150 + j * 25, 100 + i * 25);
				renderWindow.draw(sprPieO);
			}
			else if (mBoard[i][j] == TURN_HUMAN)
			{
				sprPieX.setPosition(150 + j * 25, 100 + i * 25);
				renderWindow.draw(sprPieX);
			}
		}
	}
}
void PlayerVsPlayerScene::update(sf::RenderWindow &renderWindow)
{

}

int PlayerVsPlayerScene::testWin(int cl, int rw)
{
	int r = 0, c = 0;
	int i;
	bool pl, pc;
	while (c < 15)
	{
		pl = true; pc = true;
		for (i = 0; i < 6; i++)
		{
			if (mBoard[cl][c + i] != 1)
				pl = false;
			if (mBoard[cl][c + i] != 2)
				pc = false;
		}
		if (pl)
			return HUMAN;
		if (pc) return COM;
		c++;
	}

	while (r < 15)
	{
		pl = true; pc = true;
		for (i = 0; i < 6; i++)
		{
			if (mBoard[r + i][rw] != 1)
				pl = false;
			if (mBoard[r + i][rw] != 2)
				pc = false;
		}
		if (pl) return HUMAN;
		if (pc) return COM;
		r++;
	}

	r = rw; c = cl;
	while (r > 0 && c > 0) { r--; c--; }
	while (r <= 15 && c <= 15)
	{
		pl = true; pc = true;
		for (i = 0; i < 6; i++)
		{
			if (mBoard[c + i][r + i] != 1)
				pl = false;
			if (mBoard[c + i][r + i] != 2)
				pc = false;
		}
		if (pl) return HUMAN;
		if (pc) return COM;
		r++; c++;
	}

	r = rw; c = cl;
	while (r < 19 && c > 0) { r++; c--; }
	while (r >= 4 && c <= 15)
	{
		pl = true; pc = true;
		for (i = 0; i < 6; i++)
		{
			if (mBoard[r - i][c + i] != 1)
				pl = false;
			if (mBoard[r - i][c + i] != 2)
				pc = false;
		}
		if (pl) return HUMAN;
		if (pc) return COM;
		r--; c++;
	}
	return 0;
}
void PlayerVsPlayerScene::onMouseClick(sf::Vector2i mousePositon)
{
	if (fEnd == 0 && mousePositon.x >= 150 && mousePositon.y >= 100)
	{
		pos.y = int((mousePositon.x - 150) / 25);
		pos.x = int((mousePositon.y - 100) / 25);
		if (mBoard[pos.x][pos.y] == 0)
		{
			if (turnPlayer == 1)
			{
				mBoard[pos.x][pos.y] = 1;
				sprLastPosition.setPosition(150 + pos.y * 25, 100 + pos.x * 25);
				if (testWin(pos.x, pos.y) == 1)
				{
					fEnd = 1;
					sprWin.setPosition(0, 50);
				}
				turnPlayer = 2;
			}
			else if (turnPlayer == 2)
			{
				mBoard[pos.x][pos.y] = 2;
				sprLastPosition.setPosition(150 + pos.y * 25, 100 + pos.x * 25);
				if (testWin(pos.x, pos.y) == 2)
				{
					fEnd = 2;
					sprWin.setPosition(600, 50);
				}
				turnPlayer = 1;
			}
		}
	}
	if (mousePositon.y >= 550 && mousePositon.y <= 600)
	{
		if (mousePositon.x <= 150 && mousePositon.x >= 50)
		{
			fEnd = 0;
			for (int i = 0; i < BOARD_SIZE; i++)
			{
				for (int j = 0; j < BOARD_SIZE; j++)
				{
					mBoard[i][j] = NOT_PIE;
				}
			}
			sprWin.setPosition(-5000, -5000);
			sprLastPosition.setPosition(-5000, -5000);
		}
		else if (mousePositon.x <= 750 && mousePositon.x >= 700)
		{
			GameManager::getInstance()->getStackScreen()->pop();
		}
	}
}
