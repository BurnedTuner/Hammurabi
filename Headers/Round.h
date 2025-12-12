#pragma once
#include "../Headers/Constants.h"

struct RoundData
{
    int harvest = 2;
    int price = 0;
    int mortality = 0;
    int came = 5;
    bool plague = false;
    int ratFood = 200;
};

int deathProc(const int &population, const int &foodAmount);
int cameProc(const int &mortarity, const int &harvest, const int &balance);
