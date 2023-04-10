#include "game.hpp"

Game::Game(Player &p1, Player &p2) : p1(p1), p2(p2)
{
    std::array<int, 13> numbers;
    numbers.fill(4);
    std::vector<Card> cardsP1;
    std::vector<Card> cardsP2;
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
            if (cardsDivided % 2 == 0)
                cardsP1.push_back(toDivide);
            else
                cardsP2.push_back(toDivide);
            cardsDivided++;
        }
    }
    p1.setCards(cardsP1);
    p2.setCards(cardsP2);
}

void Game::playTurn() {}
void Game::printLastTurn() {}
void Game::playAll() {}
void Game::printWiner() {}
void Game::printLog() {}
void Game::printStats() {}