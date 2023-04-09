#include "card.hpp"
Card::Card(int num)
{
    number = num;
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