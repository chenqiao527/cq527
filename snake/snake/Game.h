#pragma once
#include "Food.h"
#include "Csnake.h"
class Game
{
public:
	Food *food;
	Csnake *snake;
	Csnake *newsnake;
	int score;
	int level;
public:
	static const int KUP;
	static const int KLEFT;
	static const int WIDTH;
	static const int HEIGHT;
	static const int SCORE_SET;
	static const int LEVEL_SET;
public:
	Game();
	~Game();
	void BegingameInterface();//画游戏开始界面
	void DrowgameArea();//画游戏控制界面
	void DrowgameInfo();//画游戏信息界面
	void run();//运行蛇
	bool changeLevel();
	bool checkwall();
	bool eatself();
	void Gameinfo();//游戏规则介绍
	void changemodel();
	void newmodel();
	bool newcheckwall();
};

