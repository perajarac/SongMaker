#ifndef _skup_h_
#define _skup_h_
#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 100;

class Skup {
private:
    char elementi[MAX_SIZE];
    int brojEl;
    bool sadrzi(char c);

public:
    Skup(string s) {
        brojEl = 0;
        for (auto x : s) {
            elementi[brojEl++] = x;
        }
    }

    Skup(const Skup&) = delete;
    Skup& operator=(const Skup&) = delete;

    Skup& operator+=(char c);
    bool operator()(char c);

};
#endif