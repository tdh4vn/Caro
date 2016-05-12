#include "GameCaro.h"
#include "GameManager.h"
#include "GameMenu.h"
#include "ImageDirection.h"
#include "stdio.h"

GameCaro::GameCaro()
{
}

GameCaro::~GameCaro()
{
}


void GameCaro::run()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Co Caro - Tdh4vn");
	window.setMouseCursorVisible(false);
	sf::View fixed = window.getView();
	GameManager *gameManager = GameManager::getInstance();
	GameMenu * gameMenu = new GameMenu();
	gameManager->getStackScreen()->push(gameMenu);
	sf::Texture texCursor;
	texCursor.loadFromFile(SPR_CURSOR);
	sprCursor.setTexture(texCursor);

	while (window.isOpen())
	{
		sf::Vector2i mousePostion = sf::Mouse::getPosition(window);// lay toa do chuot
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)// bat su kien click chuot
				{
					gameManager->getInstance()->getStackScreen()->top()->onMouseClick(mousePostion);
				}
			}
			/*
			else if (stage == 2)
			{
			if (fEnd == 0 && mouse_position.x >= 150 && mouse_position.y >= 100)
			{
			pos.y = int((mouse_position.x - 150) / 25);
			pos.x = int((mouse_position.y - 100) / 25);

			if (banco[pos.x][pos.y] == 0)
			{
			banco[pos.x][pos.y] = 1;

			if (testWin(pos.x, pos.y) == 1){ fEnd = 1; spr_win.setPosition(0, 50); }
			else
			{
			AI();
			if (fWin)
			{
			_x = WinMove[0].x;
			_y = WinMove[0].y;
			}
			else
			{
			eval(2, eBoard);
			Point temp;
			temp = eBoard.getPositionOfMaxPoint();
			_x = temp.x;
			_y = temp.y;
			}
			banco[_x][_y] = 2;
			spr_ovd.setPosition(150 + _y * 25, 100 + _x * 25);
			if (testWin(_x, _y) == 2) { fEnd = 2; spr_win.setPosition(600, 50); }
			}
			}
			}
			if (mouse_position.y >= 550 && mouse_position.y <= 600)
			{
			if (mouse_position.x <= 150 && mouse_position.x >= 50)
			{
			fEnd = 0;
			for (int i = 0; i<20; i++)
			for (int j = 0; j<20; j++)
			banco[i][j] = 0;
			spr_win.setPosition(-5000, -5000);
			spr_ovd.setPosition(-5000, -5000);
			eBoard.rsBoard();
			}
			else if (mouse_position.x <= 750 && mouse_position.x >= 700)
			{
			fEnd = 0;
			stage = 0;
			for (int i = 0; i<20; i++)
			for (int j = 0; j<20; j++)
			banco[i][j] = 0;
			spr_win.setPosition(-5000, -5000);
			spr_ovd.setPosition(-5000, -5000);
			eBoard.rsBoard();
			}
			}
			}//end of else if (stage == 2)
			else if (stage == 1)
			{
			if (fEnd == 0 && mouse_position.x >= 150 && mouse_position.y >= 100)
			{
			pos.y = int((mouse_position.x - 150) / 25);
			pos.x = int((mouse_position.y - 100) / 25);
			cout << pos.y << " " << pos.x;
			if (banco[pos.x][pos.y] == 0)
			{
			if (turnPlayer == 1)
			{
			banco[pos.x][pos.y] = 1;
			spr_ovd.setPosition(150 + pos.y * 25, 100 + pos.x * 25);
			if (testWin(pos.x, pos.y) == 1) { fEnd = 1; spr_win.setPosition(0, 50); }
			turnPlayer = 2;
			}
			else if (turnPlayer == 2)
			{
			banco[pos.x][pos.y] = 2;
			spr_ovd.setPosition(150 + pos.y * 25, 100 + pos.x * 25);
			if (testWin(pos.x, pos.y) == 2) { fEnd = 2; spr_win.setPosition(600, 50); }
			turnPlayer = 1;
			}

			}
			}
			if (mouse_position.y >= 550 && mouse_position.y <= 600)
			{
			if (mouse_position.x <= 150 && mouse_position.x >= 50)
			{
			fEnd = 0;
			for (int i = 0; i<20; i++)
			for (int j = 0; j<20; j++)
			banco[i][j] = 0;
			spr_win.setPosition(-5000, -5000);
			spr_ovd.setPosition(-5000, -5000);
			eBoard.rsBoard();
			}
			else if (mouse_position.x <= 750 && mouse_position.x >= 700)
			{
			fEnd = 0;
			stage = 0;
			for (int i = 0; i<20; i++)
			for (int j = 0; j<20; j++)
			banco[i][j] = 0;
			spr_win.setPosition(-5000, -5000);
			spr_ovd.setPosition(-5000, -5000);
			eBoard.rsBoard();
			}
			}
			}
			else if (stage == 3)
			{
			stage = 0;
			}
			}//end of if (event.mouseButton.button == sf::Mouse::Left)




			}
			*/
			/*
			if (stage == 0)
			{
			
		
			}
			else if (stage == 1 || stage == 2)
			{
			
			}
			}
			if (mouse_position.y <= 600 && mouse_position.y >= 550)
			{
			if (mouse_position.x >= 50 && mouse_position.x <= 150)
			{
			spr_selectIcon.setPosition(50, 550);
			window.draw(spr_selectIcon);
			}
			else if (mouse_position.x >= 700 && mouse_position.x <= 750)
			{
			spr_selectIcon.setPosition(700, 550);
			window.draw(spr_selectIcon);
			}
			}

			window.draw(spr_P1);
			window.draw(spr_P2);
			window.draw(spr_try);
			window.draw(spr_back);
			window.draw(spr_win);
			window.draw(spr_vs);
			window.draw(spr_ovd);
			}
			else if (stage == 3)
			{
			window.draw(spr_bg0);
			window.draw(spr_S3);

			}
			*/
		}

		window.clear();
		gameManager->getInstance()->getStackScreen()->top()->update(window);
		gameManager->getInstance()->getStackScreen()->top()->draw(window);
		sprCursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		window.draw(sprCursor);
		window.display();
	}
}