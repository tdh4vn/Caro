#include "GameManager.h"


GameManager* _sharePointer;

GameManager::GameManager()
{
	stackScreen = new std::stack<Scene*>();
}


GameManager::~GameManager()
{
}

GameManager* GameManager::getInstance()
{
	if (_sharePointer == NULL){
		_sharePointer = new GameManager();
	}
	return _sharePointer;
}

std::stack<Scene*>* GameManager::getStackScreen()
{
	return stackScreen;
}
