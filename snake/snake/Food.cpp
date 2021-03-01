#include "Food.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int WIDTH = 120;
const int HEIGHT =30;
const int KLEFT = 6;
const int KUP = 6;
Food::Food(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_pic = pic;
}

void Food:: cre_food()
{
	//(rand()%(b-a))+a+1生成(a,b]区间的随机数
	srand((int)time(0));
	m_x = (rand() % ((WIDTH / 2 - 1) - KLEFT)) + KLEFT + 1;
	m_y = (rand() % ((HEIGHT-2)-KUP))+KUP+1;
}

