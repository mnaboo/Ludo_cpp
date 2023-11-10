#include "Dice.h"
#include <cstdlib>

int Dice::Roll()
{
    int random_number = rand() % 6;

    return random_number + 1;
}

