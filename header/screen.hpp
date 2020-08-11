
#ifndef Screen_H
#define Screen_H

#include <iostream>
#include <graphics.h>
#include <string>
using namespace std;

class Screen
{
protected:
    int x, y, dx, dy, width, height, color;
    int initialX, initialY;
    int sWidth, sHeight;
    int score, mistake;
    int b_Left, b_Right, b_Top, b_Bottom, b_Color;
    Screen *b;
    Screen *p[7];
    POINT cursorPosition;

public:
    Screen(int _x=0 , int _y = 0, int _width = 0, int _height = 0, int _dx = 0, int _dy = 0, int _color = WHITE);
    void setScreen(int _w, int _h);
    void setX(int _x);
    void setY(int _y);
    void B_setLeft(int newLeft);
    void B_setRight(int newRight);
    void B_setTop(int newTop);
    void B_setBottom(int newBottom);
    void B_setColor(int newColor);
    void setScore(int newScore);
    void setDefaultPosition();
    void setMistake(int newMistake);
    void setColor(int _c);


    int getTop();
    int getBottom();
    int getRight();
    int getLeft();
    int getX();
    int getY();
    int getB_Left();
    int getB_Right();
    int getB_Top();
    int getB_Bottom();
    int getB_Color();
    int getInitialX() { return initialX; };
    int getInitialY() { return initialY; };
    void getNextRectangle();
    int getMistake();
    void getMousePos();

    void gameOver();
    void B_Draw();
    void celebration();
    void _draw(int c);
    void draw();
    void undraw();
    void move();
    void displayScore();
    void menu();
    void createButtons();
    void background();
    void displayMenu();
    void backToMenuButton();
};

#endif