#pragma once

#include <iostream>
#include <functional>
#include "Round.h"
#include "Constants.h"

struct GameData
{
    int population = 100;
    int balance = 2800;
    int territory = 1000;

    int round = 1;
    int resultMortality = 0;
    int desiredFood = 0;
    int desiredHarvest = 300;
};

char validateInput(const std::string &text, std::function<bool (int)> validator);

void roundResults(GameData& game, RoundData& round);
void gameResults(GameData& game);