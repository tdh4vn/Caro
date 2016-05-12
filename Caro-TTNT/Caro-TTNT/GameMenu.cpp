#include "GameMenu.h"
#include "ImageDirection.h"
#include "iostream"
#include "GameManager.h"
#include "PlayVsComputerScene.h"
#include "PlayerVsPlayerScene.h"

GameMenu::GameMenu()
{
	loadSprite();
}


GameMenu::~GameMenu()
{
}

void GameMenu::loadSprite()
{
	texBackground.loadFromFile(SPR_BG_MENU);
	texButtonSelect.loadFromFile(SPR_SELECT);
	texButtonPvP.loadFromFile(SPR_BUTTON_PVP);
	texButtonPvC.loadFromFile(SPR_BUTTON_PVC);
	texButtonInfo.loadFromFile(SPR_BUTTON_INFO);
	texButtonExit.loadFromFile(SPR_BUTTON_EXIT);


	sprButtonSelect.setTexture(texButtonSelect);
	sprBackground.setTexture(texBackground);
	sprButtonPvP.setTexture(texButtonPvP);
	sprButtonPvC.setTexture(texButtonPvC);
	sprButtonInfo.setTexture(texButtonInfo);
	sprButtonExit.setTexture(texButtonExit);
	

	sprBackground.setPosition(0, 0);
	sprButtonSelect.setPosition(-5000, -5000);
	sprButtonPvP.setPosition(250, 300);
	sprButtonPvC.setPosition(250, 375);
	sprButtonInfo.setPosition(250, 450);
	sprButtonExit.setPosition(250, 525);
}


void GameMenu::draw(sf::RenderWindow &renderWindow)
{
	renderWindow.draw(sprBackground);
	renderWindow.draw(sprButtonPvP);
	renderWindow.draw(sprButtonPvC);
	renderWindow.draw(sprButtonInfo);
	renderWindow.draw(sprButtonExit);
	renderWindow.draw(sprButtonSelect);
}

void GameMenu::update(sf::RenderWindow &renderWindow)
{
	sf::Vector2i mousePostion = sf::Mouse::getPosition(renderWindow);
	if (mousePostion.x>250 && mousePostion.x<550)
	{
		if (mousePostion.y>300 && mousePostion.y < 375)
		{
			sprButtonSelect.setPosition(200, 300);
		}
		if (mousePostion.y>375 && mousePostion.y < 450)
		{
			sprButtonSelect.setPosition(200, 375);
		}
		if (mousePostion.y>450 && mousePostion.y < 525)
		{
			sprButtonSelect.setPosition(200, 450);
		}
		if (mousePostion.y>525 && mousePostion.y<600)
		{
			sprButtonSelect.setPosition(200, 525);
		}
	}
}

void GameMenu::onMouseClick(sf::Vector2i mousePostion)
{
	if (mousePostion.x>250 && mousePostion.x<550)
	{
		if (mousePostion.y>300 && mousePostion.y < 375)
		{
			GameManager::getInstance()->getStackScreen()->push(new PlayerVsPlayerScene());
		}
		if (mousePostion.y>375 && mousePostion.y < 450)
		{
			GameManager::getInstance()->getStackScreen()->push(new PlayVsComputerScene());
		}
		if (mousePostion.y>450 && mousePostion.y < 525)
		{
			
		}
		if (mousePostion.y>525 && mousePostion.y<600)
		{
			exit(0);
		}
	}
}