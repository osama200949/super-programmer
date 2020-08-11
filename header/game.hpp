#ifndef GAME_H
#define GAME_H

#include <graphics.h>
#include <iostream>
#include <string>
#include "Code.hpp"
#include "Screen.hpp"
#include "Clean.hpp"
#include "Error.hpp"
using namespace std;

class Game
{
protected:
    int screenWidth, screenHeight;
    Screen s;
    Code c;
public:
    Game();
    void start();
    int getScreenWidth();
    int getScreenHeight();
};

#endif