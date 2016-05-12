#pragma once
#include "Scene.h"
class GameMenu : public Scene
{
private:
	sf::Sprite sprBackground;
	sf::Sprite sprButtonSelect;
	sf::Sprite sprButtonPvP;
	sf::Sprite sprButtonPvC;
	sf::Sprite sprButtonInfo;
	sf::Sprite sprButtonExit;
	sf::Texture texBackground;
	sf::Texture texButtonSelect;
	sf::Texture texButtonPvP;
	sf::Texture texButtonPvC;
	sf::Texture texButtonInfo;
	sf::Texture texButtonExit;
public:
	GameMenu();
	~GameMenu();
	void loadSprite();
	void draw(sf::RenderWindow &renderWindow);
	void update(sf::RenderWindow &renderWindow);
	void onMouseClick(sf::Vector2i mousePositon);
};

