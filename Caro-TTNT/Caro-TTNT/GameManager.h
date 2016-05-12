#pragma once
#include "stack"
#include "Scene.h"
class GameManager
{
private:
	std::stack<Scene*> *stackScreen;
	GameManager();
	~GameManager();
public:
	static GameManager* getInstance();
	std::stack<Scene*> *getStackScreen();
	
};

