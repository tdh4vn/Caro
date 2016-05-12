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
		
		}

		window.clear();
		gameManager->getInstance()->getStackScreen()->top()->update(window);
		gameManager->getInstance()->getStackScreen()->top()->draw(window);
		sprCursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		window.draw(sprCursor);
		window.display();
	}
}