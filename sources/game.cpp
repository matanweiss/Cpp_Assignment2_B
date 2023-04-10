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

void Game::playTurn()
{
    playTurnRecursive(0, "");
}

void Game::playTurnRecursive(int amount, std::string str)
{
    if (p1.stacksize() == 0)
    {
        p1.addCardsWon(amount / 2);
        p2.addCardsWon(amount / 2);
        return;
    }
    Card cardP1 = p1.pullCard();
    Card cardP2 = p2.pullCard();
    amount += 2;
    str += p1.getName() + " played " + cardP1.toString() + " " + p2.getName() + " played " + cardP2.toString() + ". ";
    int result = cardP1.compareTo(cardP2);
    if (result == 0)
    {
        str += "draw. ";
        if (p1.stacksize() == 0)
            return;
        p1.pullCard();
        p2.pullCard();
        playTurnRecursive(amount + 2, str);
    }
    else if (0 < result)
    {
        str += p1.getName() + " wins.";
        turns.push_back(str);
        p1.addCardsWon(amount);
    }
    else
    {
        str += p2.getName() + " wins.";
        turns.push_back(str);
        p2.addCardsWon(amount);
    }
}

void Game::printLastTurn()
{
    std::cout << turns.back() << std::endl;
}

void Game::playAll()
{
    while (p1.stacksize())
        playTurn();
}

void Game::printWiner() {}

void Game::printLog() {}

void Game::printStats() {}