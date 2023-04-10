#pragma once
#include <string>
#include <vector>
#include "card.hpp"

class Player
{
    int cardsWon;
    std::string name;
    std::vector<Card> cards;
    bool isPlaying;

public:
    Player(std::string);
    int stacksize();
    int cardesTaken();
    void setCards(std::vector<Card> &);
    Card &pullCard();
    void addCardsWon(int);
    std::string getName();
    void setIsPlaying(bool);
    bool getIsPlaying();
};
