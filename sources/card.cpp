#include "card.hpp"

std::string types[4] = {"Hearts", "Diamonds", "Spades", "Clubs"};

Card::Card(int num, int type)
{
    number = num;
    name = types[type];
}
int Card::compareTo(Card other)
{
    if (number == other.number)
        return 0;
    if (number == 1)
    {
        if (other.number == 2)
            return -1;
        else
            return 1;
    }
    if (other.number == 1)
    {
        if (number == 2)
            return 1;
        else
            return -1;
    }
    if (number < other.number)
        return -1;
    else
        return 1;
}

std::string Card::toString()
{
    switch (number)
    {
    case 1:
        return "Ace of " + name;
    case 11:
        return "Jack of " + name;
    case 12:
        return "Queen of " + name;
    case 13:
        return "King of " + name;
    default:
        return std::to_string(number) + " of " + name;
    }
}
