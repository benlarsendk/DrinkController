#ifndef DRINKER
#define DRINKER

#include <iostream>
#include <vector>

using namespace std;

struct Content
{
    string name;
    int addr;
};

struct DrinkContent
{
    public:
    string name;
    int amount;
};

struct Drink
{
public:
    Drink()
{
    for (int i = 0; i < 5; i++)
    {
        content[i].name = "NOT_DECLARED";
        content[i].amount = 0;
    }
    name = "NOT_DECLARED";
    path = "STD/PATH/TO/TMP.png";

    }

    string name;
    string path;
    DrinkContent content[5];

    Drink(const Drink& Copy){
    this->name = Copy.name;
    for (int i = 0; i < 5; i++){
        this->content[i] = Copy.content[i];
    }
    }
};
#endif // DRINKER
