#include "Game.h"
#include <string>
#include <Windows.h>
#include <iostream>
using namespace std;

const int Game:: KUP = 6;
const int Game:: KLEFT = 6;
const int Game:: WIDTH = 120;
const int Game:: HEIGHT = 30;
const int Game::SCORE_SET = 0;
const int Game::LEVEL_SET = 0;

Game :: Game()
{
    score = SCORE_SET;
    level = LEVEL_SET;
    food = new Food;
    snake = new Csnake;
    newsnake = new Csnake;
}
Game::~Game()
{
    delete food;
    food = NULL;
    delete snake;
    snake = NULL;
    delete newsnake;
    newsnake = NULL;
}
void Game::BegingameInterface()
{
    int num;
    Unit::gotoxy(50, 8);
    cout << "Hey!guys.Welcome Back!";
    Unit::gotoxy(50, 10);
    cout << "Long Time No See";
    Unit::gotoxy(50, 12);
    cout << "��ʼ��Ϸ��1" << "\t" << "����˵����2" << "\t" << "�˳���Ϸ��3";
    Unit::gotoxy(50, 14);
    cout << "���������ǵ����֣�";
    cin >> num;
    switch (num)
    {
    case 1:
        run();
        break;
    case 2:
        system("cls");
        Gameinfo();
        break;
    case 3:
        system("cls");
        cout << " ";
        break;
    default:
        break;
    }

}
void Game::DrowgameArea()
{
    int width;
    int height;
    for (width = KLEFT;width < (WIDTH / 2);width++)//��
    {
        Unit::gotoxy(width, KUP);
        cout << "#";
    }

    for (width = KLEFT;width < (WIDTH / 2);width++)
    {
        Unit::gotoxy(width, HEIGHT - 1);
        cout << "#";
    }
    for (height = KUP;height < HEIGHT;height++)//��
    {
        Unit::gotoxy(KLEFT, height);
        cout << "#";
    }
    for (height = KUP;height < HEIGHT;height++)
    {
        Unit::gotoxy((WIDTH / 2), height);
        cout << "#";
    }

    for (width = (WIDTH / 2);width < WIDTH - 6;width++)//��
    {
        Unit::gotoxy(width, KUP);
        cout << "-";
    }

    for (width = (WIDTH / 2);width < WIDTH - 6;width++)
    {
        Unit::gotoxy(width, HEIGHT - 1);
        cout << "-";
    }
    for (height = KUP;height < HEIGHT;height++)//��
    {
        Unit::gotoxy(WIDTH - 6, height);
        cout << "|";
    }
    for (height = KUP;height < HEIGHT;height++)
    {
        Unit::gotoxy((WIDTH / 2)+1, height);
        cout << "|";
    }
}
void Game::DrowgameInfo()
{
    Unit::gotoxy(30, 5);
    cout << "-̰����-";
    Unit::gotoxy((WIDTH / 2) + 4, KUP + 2);
    cout << "#�༭��:����";
    Unit::gotoxy((WIDTH / 2) + 4, KUP + 4);
    cout << "#Level:"<<level;
    Unit::gotoxy((WIDTH / 2) + 4, KUP + 6);
    cout << "#��Ϸ�÷�:"<<score;
    Unit::gotoxy((WIDTH / 2) + 4, KUP + 8);
    cout << "������Ƽ�����������������";
}
void Game::run()
{
    system("cls");
    DrowgameArea();
    DrowgameInfo();
    food->cre_food();
    food->show();
    while (!(checkwall()) && !eatself())
    {
        snake->move();
        snake->changedir();
        if (snake->eatfood(food))
        {
            food->cre_food();
            food->show();
            snake->growup();
            if (score < 40)
            {
                score += 2;//ÿ��ʳ��2��
                if (score == 10)
                {
                    snake->speed = 400;
                }
                else if (score == 20)
                     {
                      snake->speed = 300;
                     }
                else if (score == 30)
                    {
                      snake->speed = 200;
                    }
            }
            else
            {
                score += 1;//ÿ��ʳ��1��
                if (score == 40)
                {
                    snake->speed = 100;
                }
            }
            if (changeLevel())//�ж��Ƿ����
            {
                if (level == 6)
                {
                    system("cls");
                    Unit::gotoxy(50, 12);
                    cout << "��ϲ�㣡ͨ������" << endl;
                    changemodel();
                }
                DrowgameInfo();
            }
        }
    }//while����
    if (checkwall()) //�ж��Ƿ�ײǽ
    {
        system("cls");
        Unit::gotoxy(50, 12);
        cout << "��Ϸ��������ײ����ǽ��";
        Unit::gotoxy(50, 14);
        cout << "�ٽ����������ͣ�";
        Sleep(5000);
        //BegingameInterface();
    }
    if (eatself())//�ж��Ƿ��Բ�
    {
        system("cls");
        Unit::gotoxy(50, 12);
        cout << "��Ϸ��������ҧ�����Լ���";
        Unit::gotoxy(50, 14);
        cout<< "����ģ��ٽ�������";
        Sleep(5000);
        //BegingameInterface();
    }


}
bool Game::changeLevel()
{
    switch (score / 10)
    {
    case 0:
        level = 0;
        return 1;
    case 1://��10����Ϊ1��
        level = 1;
        return 1;
        break;
    case 2://��20����Ϊ2��
        level = 2;
        return 1;
        break;
    case 3://��30����Ϊ3��
        level = 3;
        return 1;
        break;
    default:
        //return 1;
        break;

    }//�ﵽ40�ֺ�ÿ��ʳ����Ϊ1��/��
    switch (score / 5)
    {
    case 8:
        level = 4;
        return 1;
        break;
    case 9://��45����Ϊ5��
        level = 5;
        return 1;
        break;
    case 10:
        level = 6;//50������
        return 1;
    default:
        return 1;
        break;
    }
    /*if (level == 6)
    {
        Unit::gotoxy(50, 12);
        cout << "��ϲ�㣡ͨ������" << endl;
    }*/
    
}
bool Game::checkwall()
{
    //�ж�ײǽ
    if ((snake->s_body[0].m_x <= KLEFT) || (snake->s_body[0].m_x >= (WIDTH / 2)))
    {
        return 1;
    }
    else
        if ((snake->s_body[0].m_y <= KUP) || (snake->s_body[0].m_y >= (HEIGHT - 1)))
        {
            return 1;
        }
        else return 0;
}
//�ж��Բ�
bool Game::eatself()
{
    int i;
    for (i = 4;i < snake->slength;i++)
    {
        if (snake->s_body[0].m_x == snake->s_body[i].m_x && snake->s_body[0].m_y == snake->s_body[i].m_y)//��ַ���
        {
            return 1;
        }
    }
    return 0;
}
void Game::Gameinfo()
{
    cout << "��Ϸ�����飺"<<endl;
    cout << "�ߵķ����ɡ����������������ƣ�"<<endl;
    cout << "���ֹ���"<<endl;
    cout << "һ���������ȼ���10����һ����ÿ��һ��ʳ���2�֣���Ϊ�ĵȼ���ÿ��һ��ʳ���1�֡���ߵȼ�Ϊ6����"<<endl;
    cout << "ע�⣺";
    cout << "��ҧ���Լ���ײǽ��Ϊ��Ϸʧ�ܡ�";
    cout << "  ���ؽ�����ģʽ��Ҫע�ⲻ��ײǽӴ��";
}
void Game::changemodel()
{
    system("cls");
    int number;
    Unit::gotoxy(50, 12);
    cout << "�Ƿ�����µĹؿ���";
    Unit::gotoxy(50, 14);
    cout << "yes:1 or no:0";
    Unit::gotoxy(50, 15);
    cout << "����ѡ���ǣ�";
    cin >> number;
    switch (number)
    {
    case 0:
        system("cls");
        cout << " ";
        break;
    default:
        system("cls");
        newmodel();
        break;
    }
}
void Game::newmodel()
{
    newsnake->speed = 100;
    score = 0;
    DrowgameArea();
    DrowgameInfo();
    food->cre_food();
    food->show();
    while (!newcheckwall())
    {
        newsnake->move();
        newsnake->changedir();
        if (newsnake->eatfood(food))
        {
            food->cre_food();
            food->show();
            newsnake->growup();
            score += 2;
            switch (score%3)
            {
             case 0:
                system("color 0F");
                break;
             case 1:
                system("color 0C");
                break;
             default:
                system("color 0E");
                break;
            }
            DrowgameInfo();
        }
    }//while����
    if (newcheckwall()) //�ж��Ƿ�ײǽ
    {
        system("cls");
        Unit::gotoxy(50, 12);
        cout << "��Ϸ��������ײ����ǽ��";
        Unit::gotoxy(50, 14);
        cout << "�ٽ����������ͣ�";
        Sleep(5000);
        //BegingameInterface();
    }
}
bool Game::newcheckwall()
{
    if ((newsnake->s_body[0].m_x <= KLEFT) || (newsnake->s_body[0].m_x >= (WIDTH / 2)))
    {
        return 1;
    }
    else
        if ((newsnake->s_body[0].m_y <= KUP) || (newsnake->s_body[0].m_y >= (HEIGHT - 1)))
        {
            return 1;
        }
        else return 0;
}
   