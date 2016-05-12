#pragma once
#include "SFML\Graphics.hpp"
class Scene
{
public:
	Scene();
	~Scene();
	virtual void draw(sf::RenderWindow &renderWindow) = 0;
	virtual void update(sf::RenderWindow &renderWindow) = 0;
	virtual void onMouseClick(sf::Vector2i mousePositon) = 0;
};

