#include <iostream>
#include <fstream>
#include <windows.h>
#include "Headers/Input.h"
#include "Headers/Game.h"
#include "Headers/Round.h"
#include "Headers/Constants.h"
using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    struct GameData game;
    struct RoundData round;

    checkSave(game);

    while (game.round <= GAME_LENGTH)
    {
        cout << "Мой повелитель, соизволь поведать тебе.\nВ году " << game.round << " твоего высочайшего правления..." << endl;

        round.price = 1; //replace with random later

        if (game.round > 1)
        {
            round.mortality = deathProc(game.population, game.desiredFood);
            if (round.mortality / game.population >= 0.45)
            {
                cout << "Мой повелитель, вашей империи пришел конец..." << endl;
                std::system("pause");
                return 0;
            }
            if (round.mortality > 0)
            {
                game.population -= round.mortality;
                game.resultMortality += round.mortality;
                game.balance -= game.population * LIFE_PRICE;
            }

            round.came = cameProc(round.mortality, round.harvest, game.balance);
            if (round.came > 0)
            {
                game.population += round.came;
            }

            round.plague = true; //replace with random later
            if (round.plague)
            {
                game.population /= 2;
            }

            round.ratFood = ((float)1 / 100.0f) * game.balance; //replace with random later
            game.balance -= round.ratFood;
        }

        if (game.balance < 0)
        {
            game.balance = 0;
        }

        roundResults(game, round);

        int transactionResult = transactionInput(game, -round.price);
        game.territory -= transactionResult;
        game.balance += transactionResult * round.price;
        
        transactionResult = transactionInput(game, round.price);
        game.territory += transactionResult;
        game.balance -= transactionResult * round.price;
        
        game.desiredFood = foodInput(game);
        game.balance -= game.desiredFood;
        
        round.harvest = 1; //replace with random later
        int seedInputResult = seedInput(game);
        game.desiredHarvest = seedInputResult * round.harvest;
        game.balance += game.desiredHarvest - (seedInputResult * SEED_PRICE);

        if (promptSave(game))
        {
            std::system("pause");
            return 0;
        }
        game.round++;
    }
    gameResults(game);

    std::system("pause");

    return 0;
}
