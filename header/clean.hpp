#ifndef CLEAN_H
#define CLEAN_H

#include <graphics.h>
#include <string>
#include <iostream>
#include "Code.hpp"
using namespace std;

class Clean : public Code
{
protected:

public:
    Clean();
    int getScore();
    string getTextFile(int _i);
};


#endif