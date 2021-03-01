#include "Unit.h"
#include <iostream>
#include <windows.h>
#include <conio.h>    //跳到屏幕指定坐标
using namespace std;

Unit :: Unit(){}
Unit::Unit(int x, int y, char pic)
{
    m_x = x;
    m_y = y;
    m_pic = pic;
}

void Unit::gotoxy()
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
    csbiInfo.dwCursorPosition.X = m_x;
    csbiInfo.dwCursorPosition.Y = m_y;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void Unit:: gotoxy(int x, int y)
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
    csbiInfo.dwCursorPosition.X = x;
    csbiInfo.dwCursorPosition.Y = y;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void Unit::show()
{
    gotoxy();
    cout << m_pic << endl;
}

void Unit::erase()
{
    gotoxy();
    cout << " " << endl;
}

