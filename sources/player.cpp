#include "player.hpp"

Player::Player(std::string name)
{
    cardsWon = 0;
    this->name = name;
}

int Player::stacksize()
{
    return cards.size();
}

int Player::cardesTaken()
{
    return cardsWon;
}

void Player::setCards(std::vector<Card> &cards)
{
    this->cards = cards;
}
