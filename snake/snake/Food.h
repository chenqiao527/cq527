#pragma once
#include "Unit.h"
class Food :
    public Unit
{
public:
    Food(int x=0, int y=0, char pic = '$');
    void cre_food();
};

