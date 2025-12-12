#pragma once

#include <iostream>
#include <fstream>
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
    
    void saveData();
    void loadData();
};

char validateInput(const std::string &text, std::function<bool (int)> validator);

void checkSave(GameData& game);
bool promptSave(GameData& game);
void roundResults(GameData& game, RoundData& round);
void gameResults(GameData& game);