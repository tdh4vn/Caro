#include "PlayVsComputerScene.h"
#include "ImageDirection.h"
#include "Constant.h"
#include "iostream"
#include "GameManager.h"


PlayVsComputerScene::PlayVsComputerScene()
{
	loadSprite();
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			mBoard[i][j] = NOT_PIE;
		}
	}
	DScore[0] = 0;
	DScore[1] = 1;
	DScore[2] = 9;
	DScore[3] = 81;
	DScore[4] = 729;
	DScore[5] = 1458;
	AScore[0] = 0;
	AScore[1] = 2;
	AScore[2] = 18;
	AScore[3] = 162;
	AScore[4] = 1458;
	AScore[5] = 2916;
}


PlayVsComputerScene::~PlayVsComputerScene()
{
}

void PlayVsComputerScene::loadSprite()
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

void PlayVsComputerScene::eval(int player, EvalChessBoard& eBoard)
{
	int rw, cl, ePC, eHuman;
	eBoard.rsBoard();

	//Danh gia theo hang
	for (rw = 0; rw < BOARD_SIZE; rw++)
		for (cl = 0; cl < BOARD_SIZE - 6; cl++)
		{
			ePC = 0; eHuman = 0;
			for (int i = 0; i < 6; i++)
			{
				if (mBoard[rw][cl + i] == HUMAN) eHuman++;
				if (mBoard[rw][cl + i] == COM) ePC++;
			}

			if (eHuman * ePC == 0 && eHuman != ePC)
			{
				for (int i = 0; i < 6; i++)
				{
					if (mBoard[rw][cl + i] == NOT_PIE) // Neu o chua duoc danh
					{
						if (eHuman == 0)
						{
							if (player == HUMAN)
							{
								eBoard.eBoard[rw][cl + i] += DScore[ePC];
							}
							else
							{
								eBoard.eBoard[rw][cl + i] += AScore[ePC];
							}
							
						}
						
						if (ePC == 0)
						{
							if (player == COM)
							{
								eBoard.eBoard[rw][cl + i] += DScore[eHuman];
							}
							else
							{
								eBoard.eBoard[rw][cl + i] += AScore[eHuman];
							}
							
						}
						if (eHuman == 5 || ePC == 5)
						{
							eBoard.eBoard[rw][cl + i] *= 2;
						}
					}
				}
			}
		}

	//Danh gia theo cot
	for (cl = 0; cl < BOARD_SIZE; cl++)
		for (rw = 0; rw < BOARD_SIZE - 6; rw++)
		{
			ePC = 0; eHuman = 0;
			for (int i = 0; i < 6; i++)
			{
				if (mBoard[rw + i][cl] == 1) eHuman++;
				if (mBoard[rw + i][cl] == 2) ePC++;
			}

			if (eHuman * ePC == 0 && eHuman != ePC)
			{
				for (int i = 0; i < 6; i++)
				{
					if (mBoard[rw + i][cl] == 0) // Neu o chua duoc danh
					{
						if (eHuman == 0)
						{
							if (player == HUMAN)
							{
								eBoard.eBoard[rw + i][cl] += DScore[ePC];
							}
							else
							{
								eBoard.eBoard[rw + i][cl] += AScore[ePC];
							}
							
						}
						if (ePC == 0)
						{
							if (player == COM)
							{
								eBoard.eBoard[rw + i][cl] += DScore[eHuman];
							}
							else
							{
								eBoard.eBoard[rw + i][cl] += AScore[eHuman];
							}
							
						}
						if (eHuman == 5 || ePC == 5)
						{
							eBoard.eBoard[rw + i][cl] *= 2;
						}
					}
				}
			}
		}

	//Danh gia duong cheo xuong
	for (cl = 0; cl < BOARD_SIZE; cl++)
		for (rw = 0; rw < BOARD_SIZE - 6; rw++)
		{
			ePC = 0; eHuman = 0;
			for (int i = 0; i < 6; i++)
			{
				if (mBoard[rw + i][cl + i] == 1) eHuman++;
				if (mBoard[rw + i][cl + i] == 2) ePC++;
			}

			if (eHuman * ePC == 0 && eHuman != ePC)
			{
				for (int i = 0; i < 6; i++)
				{
					if (mBoard[rw + i][cl + i] == 0) // Neu o chua duoc danh
					{
						if (eHuman == 0)
						{
							if (player == 1)
							{
								eBoard.eBoard[rw + i][cl + i] += DScore[ePC];
							}
							else
							{
								eBoard.eBoard[rw + i][cl + i] += AScore[ePC];
							}
							
						}
						if (ePC == 0)
						{
							if (player == 2)
							{
								eBoard.eBoard[rw + i][cl + i] += DScore[eHuman];
							}
							else
							{
								eBoard.eBoard[rw + i][cl + i] += AScore[eHuman];
							}
							
						}
						if (eHuman == 5 || ePC == 5)
						{
							eBoard.eBoard[rw + i][cl + i] *= 2;
						}
					}
				}
			}
		}

	//Danh gia duong cheo len
	for (rw = 5; rw < BOARD_SIZE; rw++)
		for (cl = 0; cl < BOARD_SIZE - 6; cl++)
		{
			ePC = 0; eHuman = 0;
			for (int i = 0; i < 6; i++)
			{
				if (mBoard[rw - i][cl + i] == 1) eHuman++;
				if (mBoard[rw - i][cl + i] == 2) ePC++;
			}

			if (eHuman * ePC == 0 && eHuman != ePC)
			{
				for (int i = 0; i < 6; i++)
				{
					if (mBoard[rw - i][cl + i] == 0) // Neu o chua duoc danh
					{
						if (eHuman == 0)
						{
							if (player == 1)
							{
								eBoard.eBoard[rw - i][cl + i] += DScore[ePC];
							}
							else
							{
								eBoard.eBoard[rw - i][cl + i] += AScore[ePC];
							}
							
						}
						if (ePC == 0)
						{
							if (player == 2)
							{
								eBoard.eBoard[rw - i][cl + i] += DScore[eHuman];
							}
							else
							{
								eBoard.eBoard[rw - i][cl + i] += AScore[eHuman];
							}
							
						}
						if (eHuman == 5 || ePC == 5)
						{
							eBoard.eBoard[rw - i][cl + i] *= 2;
						}
					}
				}
			}
		}
}


void PlayVsComputerScene::search()
{
	if (depth > MAX_DEPTH) 
	{
		return;
	}
	depth++;
	fWin = false;
	bool fLose = false;
	Point pcMove;
	Point humanMove;
	int countMove = 0;
	eval(TURN_COM, evalChessBoard);
	Point temp;
	for (int i = 0; i < maxMove; i++)
	{
		temp = evalChessBoard.getPositionOfMaxPoint();
		PCMove[i] = temp;
		evalChessBoard.eBoard[temp.x][temp.x] = 0;
	}
	countMove = 0;
	while (countMove < maxMove)
	{

		pcMove = PCMove[countMove++];
		mBoard[pcMove.x][pcMove.y] = COM;
		WinMove[depth - 1] = pcMove;
		evalChessBoard.rsBoard();
		eval(TURN_HUMAN, evalChessBoard);
		for (int i = 0; i < maxMove; i++)
		{
			temp = evalChessBoard.getPositionOfMaxPoint();
			PlayerMove[i] = temp;
			evalChessBoard.eBoard[temp.x][temp.y] = 0;
		}
		for (int i = 0; i < maxMove; i++)
		{
			humanMove = PlayerMove[i];
			mBoard[humanMove.x][humanMove.y] = HUMAN;
			if (testWin(pcMove.x, pcMove.y) == COM) fWin = true;
			if (testWin(humanMove.x, humanMove.y) == HUMAN) fLose = true;
			if (fLose)
			{
				mBoard[pcMove.x][pcMove.y] = NOT_PIE;
				mBoard[humanMove.x][humanMove.y] = NOT_PIE;
				break;
			}
			if (fWin)
			{
				mBoard[pcMove.x][pcMove.y] = NOT_PIE;
				mBoard[humanMove.x][humanMove.y] = NOT_PIE;
				return;
			}
			search();
			mBoard[humanMove.x][humanMove.y] = NOT_PIE;
		}
		mBoard[pcMove.x][pcMove.y] = NOT_PIE;
	}
}
void PlayVsComputerScene::draw(sf::RenderWindow &renderWindow)
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
void PlayVsComputerScene::update(sf::RenderWindow &renderWindow)
{
	sf::Vector2i mousePositon = sf::Mouse::getPosition(renderWindow);
	
}
int PlayVsComputerScene::testWin(int cl, int rw)
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

void PlayVsComputerScene::AI()
{
	depth = 0;
	search();
}
void PlayVsComputerScene::onMouseClick(sf::Vector2i mousePositon)
{
	if (fEnd == 0 && mousePositon.x >= 150 && mousePositon.y >= 100)
	{
		pos.y = int((mousePositon.x - 150) / 25);
		pos.x = int((mousePositon.y - 100) / 25);

		if (mBoard[pos.x][pos.y] == NOT_PIE)
		{
			mBoard[pos.x][pos.y] = HUMAN;

			if (testWin(pos.x, pos.y) == HUMAN)
			{
				fEnd = HUMAN;
				sprWin.setPosition(0, 50);
			}
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
					eval(TURN_COM, evalChessBoard);
					Point temp;
					temp = evalChessBoard.getPositionOfMaxPoint();
					_x = temp.x;
					_y = temp.y;
				}
				mBoard[_x][_y] = COM;
				sprLastPosition.setPosition(150 + _y * 25, 100 + _x * 25);
				if (testWin(_x, _y) == COM)
				{
					fEnd = COM;
					sprWin.setPosition(600, 50);
				}
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
			evalChessBoard.rsBoard();
		}
		else if (mousePositon.x <= 750 && mousePositon.x >= 700)
		{
			GameManager::getInstance()->getStackScreen()->pop();
		}
	}
}
