#pragma once
#include "player.hpp"
#include <array>
#include <vector>
#include <random>
#include <iostream>

class Game
{
private:
    Player &p1;
    Player &p2;
    std::string *turns;

public:
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    Game(Player &, Player &);
};

namespace ariel
{

};