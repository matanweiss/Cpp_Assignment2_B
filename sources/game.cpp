#include "game.hpp"
#include <array>
#include <vector>
#include <random>
#include <iostream>

Game::Game(Player p1, Player p2)
{
    std::array<int, 13> numbers;
    numbers.fill(4);
    std::vector<Card> cardsP1;
    std::vector<Card> cardsP2;
    bool isP1 = true;
    int cardsDivided = 0;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 12);
    while (cardsDivided < 52)
    {
        size_t currentNumber = dist6(rng);
        if (0 < numbers.at(currentNumber))
        {
            Card toDivide(currentNumber + 1, numbers.at(currentNumber) - 1);
            numbers.at(currentNumber)--;
            if (isP1)
                cardsP1.push_back(toDivide);
            else
                cardsP2.push_back(toDivide);
            isP1 = !isP1;
            cardsDivided++;
        }
    }
    std::cout << "p1:" << std::endl;
    for (Card &c : cardsP1)
    {
        std::cout << c.toString() << std::endl;
    }
    std::cout << "p2:" << std::endl;
    for (Card &c : cardsP2)
    {
        std::cout << c.toString() << std::endl;
    }
}

void Game::playTurn() {}
void Game::printLastTurn() {}
void Game::playAll() {}
void Game::printWiner() {}
void Game::printLog() {}
void Game::printStats() {}