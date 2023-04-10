#include "game.hpp"

Game::Game(Player &p1, Player &p2) : p1(p1), p2(p2)
{
    if (p1.getIsPlaying() || p2.getIsPlaying())
        throw std::runtime_error("a player is already playing another game");
    p1.setIsPlaying(true);
    p2.setIsPlaying(true);
    draws = 0;
    winsP1 = 0;
    winsP2 = 0;

    // creating and dividing the cards
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
    if (&p1 == &p2)
        throw std::invalid_argument("a player can't play agains himself");
    if (p1.stacksize() == 0)
        throw std::runtime_error("the game has already ended");
    playTurnRecursive(0, "");
}

void Game::playTurnRecursive(int amount, std::string str)
{
    // if the game has ended
    if (p1.stacksize() == 0)
    {
        p1.addCardsWon(amount / 2);
        p2.addCardsWon(amount / 2);
        p1.setIsPlaying(false);
        p2.setIsPlaying(false);
        return;
    }

    Card cardP1 = p1.pullCard();
    Card cardP2 = p2.pullCard();
    amount += 2;
    str += p1.getName() + " played " + cardP1.toString() + " " + p2.getName() + " played " + cardP2.toString() + ". ";
    int result = cardP1.compareTo(cardP2);

    // if there is a draw
    if (result == 0)
    {
        draws += 1;
        str += "draw. ";
        if (p1.stacksize() == 0)
            return;
        p1.pullCard();
        p2.pullCard();
        playTurnRecursive(amount + 2, str);
    }

    // player 1 wins
    else if (0 < result)
    {
        winsP1 += 1;
        str += p1.getName() + " wins.";
        turns.push_back(str);
        p1.addCardsWon(amount);
    }

    // player 2 wins
    else
    {
        winsP2 += 1;
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

void Game::printWiner()
{
    if (p1.stacksize() != 0)
        std::cout << "the game has not ended yet" << std::endl;
    if (p1.cardesTaken() == p2.cardesTaken())
        std::cout << "there is a tie" << std::endl;
    else if (p1.cardesTaken() < p2.cardesTaken())
        std::cout << p2.getName() + " won" << std::endl;
    else
        std::cout << p1.getName() + " won" << std::endl;
}

void Game::printLog()
{
    for (auto &turn : turns)
    {
        std::cout << turn << std::endl;
    }
}

void Game::printStats()
{
    std::cout << p1.getName() + ": ";
    std::cout << "win rate - " + std::to_string((float)winsP1 / turns.size()) + ", ";
    std::cout << "cards won - " + std::to_string(p1.cardesTaken()) << std::endl;
    std::cout << p2.getName() + ": ";
    std::cout << "win rate - " + std::to_string((float)winsP2 / turns.size()) + ", ";
    std::cout << "cards won - " + std::to_string(p2.cardesTaken()) << std::endl;
    std::cout << "draw rate: " + std::to_string((float)draws / turns.size()) + ", ";
    std::cout << "draws amount: " + std::to_string(draws) << std::endl;
}
