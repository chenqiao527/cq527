#pragma once
#include <vector>
#include "Unit.h"
#include "Food.h"
using namespace std;
typedef enum {
	UP,DOWN,LEFT,RIGHT
}Directions;
class Csnake
{
public:
	int head_x;
	int head_y;
	int slength;
	int speed;
	char spic;
	Directions s_dir;
	vector<Unit> s_body;
public:
	Csnake(int x=40,int y=10,Directions direction=RIGHT,int length=4,int _speed=500,char pic='*');
	void move();
	void showsnake();
	void erasesnake();
	bool eatfood(Food *food);
	void growup();
	void changedir();
};

