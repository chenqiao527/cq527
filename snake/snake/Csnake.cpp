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
	for (i = slength - 1;i > 0;i--)//����ˢ��
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
	if (GetAsyncKeyState(VK_UP) && s_dir != DOWN)            //GetAsyncKeyState���������жϺ�������ʱָ���������״̬
	{
		s_dir = UP;           //����߲�������ǰ����ʱ�򣬰��ϼ���ִ������ǰ������
	}
	else if (GetAsyncKeyState(VK_DOWN) && s_dir != UP)     //����߲�������ǰ����ʱ�򣬰��¼���ִ������ǰ������
	{
		s_dir = DOWN;
	}
	else if (GetAsyncKeyState(VK_LEFT) && s_dir != RIGHT)      //����߲�������ǰ����ʱ�򣬰������ִ������ǰ��
	{
		s_dir = LEFT;
	}
	else if (GetAsyncKeyState(VK_RIGHT) && s_dir != LEFT)     //����߲�������ǰ����ʱ�򣬰��Ҽ���ִ������ǰ��
	{
		s_dir = RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE))		//����ͣ����ִ��pause��ͣ����
	{
		while (1)
		{
			showsnake();
			Sleep(300); //sleep()������ͷ�ļ�#include <unistd.h>  �������ͣ��ֱ���ﵽ�����趨�Ĳ�����ʱ�䡣
			if (GetAsyncKeyState(VK_SPACE))      //���ո����ͣ
			{
				break;
			}
			//if (GetAsyncKeyState(VK_ESCAPE))//��ESC�˳���Ϸ
			//{
			//	system("cls");
			//	cout << " ";
			//}
		}
	}
	//if (GetAsyncKeyState(VK_ESCAPE))//��ESC�˳���Ϸ
	//{
	//	system("cls");
	//	cout << " ";
	//	//Sleep(300);
	//}
}