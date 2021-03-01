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
	void BegingameInterface();//����Ϸ��ʼ����
	void DrowgameArea();//����Ϸ���ƽ���
	void DrowgameInfo();//����Ϸ��Ϣ����
	void run();//������
	bool changeLevel();
	bool checkwall();
	bool eatself();
	void Gameinfo();//��Ϸ�������
	void changemodel();
	void newmodel();
	bool newcheckwall();
};

