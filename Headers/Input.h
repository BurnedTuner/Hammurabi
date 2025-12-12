#pragma once

#include <iostream>
#include <functional>
#include <algorithm>
#include "Constants.h"
#include "Game.h"

int getValidatedInt(const GameData& game, const std::string &text, std::function<bool (int)> validator);
int transactionInput(const GameData& game, const int& price);
int foodInput(const GameData& game);
int seedInput(const GameData& game);