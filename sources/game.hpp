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
    std::vector<std::string> turns;

public:
    void playTurn();
    void playTurnRecursive(int, std::string);
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