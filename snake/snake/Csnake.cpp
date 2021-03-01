#include "Csnake.h"
#include "Food.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
using namespace std;
//int count1 = 0;
int i,j;

Csnake::Csnake(int x, int y, Directions direction, int length, int _speed, char pic)
{
	head_x = x;
	head_y=y;
	slength=length;
	speed=_speed;
	spic=pic;
	s_dir = direction;
		for (i = 0;i < slength;i++)
		{
			Unit MyUnit(0, 0, '*');
			s_body.push_back(MyUnit);
			switch (s_dir)
			{
			case UP:
				s_body[i].m_x = head_x;
				s_body[i].m_y = head_y + i;
				break;
			case DOWN:
				s_body[i].m_x = head_x;
				s_body[i].m_y = head_y - i;
				break;
			case LEFT:
				s_body[i].m_x = head_x + i;
				s_body[i].m_y = head_y;
				break;
			case RIGHT:
				s_body[i].m_x = head_x - i;
				s_body[i].m_y = head_y;
				break;

			}

		}

}


void Csnake::move()
{
	showsnake();
	Sleep(speed);
	erasesnake();
	for (i = slength - 1;i > 0;i--)//蛇身刷新
	{
		s_body[i].m_x = s_body[i - 1].m_x;
		s_body[i].m_y = s_body[i - 1].m_y;
	}
		switch (s_dir)
		{
		case UP:
			s_body[0].m_y--;
			break;
		case DOWN:
			s_body[0].m_y++;
			break;
		case LEFT:
			s_body[0].m_x--;
			break;
		case RIGHT:
			s_body[0].m_x++;
			break;
		default:
			break;
	}
}

void Csnake::showsnake()
{
	
	for (i = 0;i < slength;i++)
	{
		s_body[i].show();
	}
	
}
void Csnake::erasesnake()
{
	for (i = 0;i < slength;i++)
	{
		s_body[i].erase();
	}
}
bool Csnake::eatfood(Food *food)
{
	for (i = 0;i < slength;i++)
	{
		if (s_body[i].m_x == food->m_x && s_body[i].m_y == food->m_y)
		{
			return 1;
		}
		else return 0;
	}
	
}
void Csnake::growup()
{
	Unit MyUnit(0, 0, '*');
	s_body.push_back(MyUnit);
	slength++;
}

void Csnake::changedir()
{
	if (GetAsyncKeyState(VK_UP) && s_dir != DOWN)            //GetAsyncKeyState函数用来判断函数调用时指定虚拟键的状态
	{
		s_dir = UP;           //如果蛇不是向下前进的时候，按上键，执行向上前进操作
	}
	else if (GetAsyncKeyState(VK_DOWN) && s_dir != UP)     //如果蛇不是向上前进的时候，按下键，执行向下前进操作
	{
		s_dir = DOWN;
	}
	else if (GetAsyncKeyState(VK_LEFT) && s_dir != RIGHT)      //如果蛇不是向右前进的时候，按左键，执行向左前进
	{
		s_dir = LEFT;
	}
	else if (GetAsyncKeyState(VK_RIGHT) && s_dir != LEFT)     //如果蛇不是向左前进的时候，按右键，执行向右前进
	{
		s_dir = RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE))		//按暂停键，执行pause暂停函数
	{
		while (1)
		{
			showsnake();
			Sleep(300); //sleep()函数，头文件#include <unistd.h>  另进程暂停，直到达到里面设定的参数的时间。
			if (GetAsyncKeyState(VK_SPACE))      //按空格键暂停
			{
				break;
			}
			//if (GetAsyncKeyState(VK_ESCAPE))//按ESC退出游戏
			//{
			//	system("cls");
			//	cout << " ";
			//}
		}
	}
	//if (GetAsyncKeyState(VK_ESCAPE))//按ESC退出游戏
	//{
	//	system("cls");
	//	cout << " ";
	//	//Sleep(300);
	//}
}