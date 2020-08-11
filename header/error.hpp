#ifndef ERROR_H
#define ERROR_H
#include <iostream>
#include <string>
#include <graphics.h>
#include "Code.hpp"
using namespace std;

class Error : public Code
{
protected:

public:
    Error();
    int getScore();
    string getTextFile(int _i);
};

#endif