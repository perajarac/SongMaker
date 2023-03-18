#include "Skup.h"

bool Skup::sadrzi(char c)
{
    for (int i = 0; i < brojEl; i++) {
        if (elementi[i] == c) {
            return true;
        }
    }
    return false;
}

Skup& Skup::operator+=(char c)
{
    if (sadrzi(c)) {
        return *this;
    }
    elementi[brojEl] = c;
    brojEl++;
    return *this;
}

bool Skup::operator()(char c)
{
    if (this->sadrzi(c)) return true;
    else return false;
}
