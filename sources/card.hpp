#pragma once
#include <string>
class Card
{
    int number;
    std::string name;

public:
    Card(int, int);
    int compareTo(Card);
    std::string toString();
};