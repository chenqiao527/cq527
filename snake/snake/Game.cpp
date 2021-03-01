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
    cout << "开始游戏：1" << "\t" << "规则说明：2" << "\t" << "退出游戏：3";
    Unit::gotoxy(50, 14);
    cout << "请输入心仪的数字：";
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
    for (width = KLEFT;width < (WIDTH / 2);width++)//宽
    {
        Unit::gotoxy(width, KUP);
        cout << "#";
    }

    for (width = KLEFT;width < (WIDTH / 2);width++)
    {
        Unit::gotoxy(width, HEIGHT - 1);
        cout << "#";
    }
    for (height = KUP;height < HEIGHT;height++)//高
    {
        Unit::gotoxy(KLEFT, height);
        cout << "#";
    }
    for (height = KUP;height < HEIGHT;height++)
    {
        Unit::gotoxy((WIDTH / 2), height);
        cout << "#";
    }

    for (width = (WIDTH / 2);width < WIDTH - 6;width++)//宽
    {
        Unit::gotoxy(width, KUP);
        cout << "-";
    }

    for (width = (WIDTH / 2);width < WIDTH - 6;width++)
    {
        Unit::gotoxy(width, HEIGHT - 1);
        cout << "-";
    }
    for (height = KUP;height < HEIGHT;height++)//高
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
    cout << "-贪吃蛇-";
    Unit::gotoxy((WIDTH / 2) + 4, KUP + 2);
    cout << "#编辑者:陈乔";
    Unit::gotoxy((WIDTH / 2) + 4, KUP + 4);
    cout << "#Level:"<<level;
    Unit::gotoxy((WIDTH / 2) + 4, KUP + 6);
    cout << "#游戏得分:"<<score;
    Unit::gotoxy((WIDTH / 2) + 4, KUP + 8);
    cout << "方向控制键：↑、↓、←、→";
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
                score += 2;//每个食物2分
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
                score += 1;//每个食物1分
                if (score == 40)
                {
                    snake->speed = 100;
                }
            }
            if (changeLevel())//判断是否晋级
            {
                if (level == 6)
                {
                    system("cls");
                    Unit::gotoxy(50, 12);
                    cout << "恭喜你！通关啦！" << endl;
                    changemodel();
                }
                DrowgameInfo();
            }
        }
    }//while结束
    if (checkwall()) //判断是否撞墙
    {
        system("cls");
        Unit::gotoxy(50, 12);
        cout << "游戏结束！您撞到了墙。";
        Unit::gotoxy(50, 14);
        cout << "再接再厉，加油！";
        Sleep(5000);
        //BegingameInterface();
    }
    if (eatself())//判断是否自残
    {
        system("cls");
        Unit::gotoxy(50, 12);
        cout << "游戏结束！您咬到了自己。";
        Unit::gotoxy(50, 14);
        cout<< "别灰心，再接再厉！";
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
    case 1://满10分升为1级
        level = 1;
        return 1;
        break;
    case 2://满20分升为2级
        level = 2;
        return 1;
        break;
    case 3://满30分升为3级
        level = 3;
        return 1;
        break;
    default:
        //return 1;
        break;

    }//达到40分后每个食物升为1个/分
    switch (score / 5)
    {
    case 8:
        level = 4;
        return 1;
        break;
    case 9://满45分升为5级
        level = 5;
        return 1;
        break;
    case 10:
        level = 6;//50分满级
        return 1;
    default:
        return 1;
        break;
    }
    /*if (level == 6)
    {
        Unit::gotoxy(50, 12);
        cout << "恭喜你！通关啦！" << endl;
    }*/
    
}
bool Game::checkwall()
{
    //判断撞墙
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
//判断自残
bool Game::eatself()
{
    int i;
    for (i = 4;i < snake->slength;i++)
    {
        if (snake->s_body[0].m_x == snake->s_body[i].m_x && snake->s_body[0].m_y == snake->s_body[i].m_y)//地址溢出
        {
            return 1;
        }
    }
    return 0;
}
void Game::Gameinfo()
{
    cout << "游戏规则简介："<<endl;
    cout << "蛇的方向由↑、↓、←、→控制；"<<endl;
    cout << "积分规则："<<endl;
    cout << "一、二和三等级满10分升一级，每吃一个食物加2分，升为四等级后每吃一个食物加1分。最高等级为6级。"<<endl;
    cout << "注意：";
    cout << "蛇咬到自己和撞墙均为游戏失败。";
    cout << "  过关进入新模式后，要注意不能撞墙哟！";
}
void Game::changemodel()
{
    system("cls");
    int number;
    Unit::gotoxy(50, 12);
    cout << "是否进入新的关卡：";
    Unit::gotoxy(50, 14);
    cout << "yes:1 or no:0";
    Unit::gotoxy(50, 15);
    cout << "您的选择是：";
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
    }//while结束
    if (newcheckwall()) //判断是否撞墙
    {
        system("cls");
        Unit::gotoxy(50, 12);
        cout << "游戏结束！您撞到了墙。";
        Unit::gotoxy(50, 14);
        cout << "再接再厉，加油！";
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
   