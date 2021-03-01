#pragma once
class Unit
{
public:
        int m_x;
        int m_y;
        char m_pic;
public:
        Unit();
        Unit(int x, int y, char pic = '*');
        void gotoxy();
        static void gotoxy(int x, int y);
        void show();
        void erase();
};