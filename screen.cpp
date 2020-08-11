#include "header/screen.hpp"

Screen::Screen(int _x, int _y, int _width, int _height, int _dx, int _dy, int _color) : x(_x), y(_y), width(_width), height(_height), dx(_dx), dy(_dy), color(_color)
{
    score = 0;
    mistake = 0;
    b_Left, b_Right, b_Top, b_Bottom, b_Color = WHITE;
    for (int i = 0; i < 7; i++){p[i] = NULL;}
    b = NULL;
}

void Screen::setScreen(int _w, int _h)
{
    sWidth = _w;
    sHeight = _h;
}
int Screen::getTop() { return y; }

int Screen::getBottom() { return y + height; }

int Screen::getRight() { return x + width; }

int Screen::getLeft() { return x; }

void Screen::setX(int _x) { x = _x; }

void Screen::setY(int _y) { y = _y; }

int Screen::getX() { return x; }

int Screen::getY() { return y; }

void Screen::_draw(int c)
{
    setfillstyle(SOLID_FILL, c);
    bar(x, y, x + width, y + height);
}
void Screen::draw(){_draw(color);}

void Screen::undraw(){_draw(BLUE);}

void Screen::move()
{
    undraw();
    x += dx;
    y += dy;
    draw();
}
void Screen::B_setLeft(int newLeft){b_Left = newLeft;}

void Screen::B_setRight(int newRight){b_Right = newRight;}

void Screen::B_setTop(int newTop){b_Top = newTop;}

void Screen::B_setBottom(int newBottom){b_Bottom = newBottom;}

void Screen::B_setColor(int newColor){b_Color = newColor;}

int Screen::getB_Left(){return b_Left;}

int Screen::getB_Right(){return b_Right;}

int Screen::getB_Top(){return b_Top;}

int Screen::getB_Bottom(){return b_Bottom;}

int Screen::getB_Color(){return b_Color;}

void Screen::setDefaultPosition()
{
    initialX = 50;
    initialY = sHeight/2 -50;
}

void Screen::getNextRectangle()
{
    undraw();
    color = BLUE;
    x = initialX;
    y = initialY;
    B_Draw();
}
void Screen::B_Draw()
{
    setcolor(b_Color);
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(b_Left, b_Top, b_Right, b_Bottom);
}
void Screen::setScore(int newScore) { score += newScore; }

void Screen::setMistake(int newMistake) { mistake += newMistake; }

int Screen::getMistake() { return mistake; }

void Screen::setColor(int _c) { color = _c; }

void Screen::displayScore()
{
    string blanck = "     ";
    
    // SCORE
    
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(sWidth - 222, 30, "SCORE");

    // number
   
    setbkcolor(BLACK);
    setcolor(YELLOW);
    outtextxy(sWidth - 222, 70, (char *)blanck.c_str());
    outtextxy(sWidth - 170, 70, (char *)to_string(score).c_str());

    // Mistake
    
    setbkcolor(BLACK);
    setcolor(WHITE);
    outtextxy(sWidth - 270, 150, "Mistakes");
   
    // number
    setbkcolor(BLACK);
    setcolor(YELLOW);
    outtextxy(sWidth - 222, 190, (char *)blanck.c_str());
    outtextxy(sWidth - 170, 190, (char *)to_string(mistake).c_str());

}

void Screen::celebration()
{
    setfillstyle(SOLID_FILL, BLACK); // You win celebration
    bar(0, 0, sWidth, sHeight);

    for (int x = 0; x < 4; x++)
    {
        displayScore();

        readimagefile("image/won2.jpg", (sWidth / 2) - 100, 25, (sWidth / 2) + 100, 125);
        delay(100);
        
        readimagefile("image/cong.jpg", 0, 300, 300, 500);
        delay(70);
        
        readimagefile("image/cong43.jpg", sWidth - 350, 300, sWidth, 500);
        delay(70);
        
        readimagefile("image/cong4.jpg", 0, 0, sWidth, sHeight);
        delay(80);
        
        readimagefile("image/black.jpg", 0, 0, sWidth, sHeight);
        delay(300);
    }
    readimagefile("image/black.jpg", 0, 0, sWidth, sHeight);
    delay(100);
    readimagefile("image/backtoMenu.jpg", 0, 0, sWidth, sHeight);
    displayScore();

    delay(200);
    getch();
}

void Screen::gameOver()
{
    setfillstyle(SOLID_FILL, BLACK);
    bar(0, 0, sWidth, sHeight);
    readimagefile("image/black2.jpg", 0, 0, sWidth, sHeight);
    
    delay(100);
    readimagefile("image/gameover.jpg", 0, 0, sWidth, sHeight);
    displayScore();
    
    delay(200);
    getch();
}

void Screen::menu() // menu
{
    initwindow(sWidth, sHeight, "Zero To Hero");
    //setcolor(WHITE);
    setfillstyle(SOLID_FILL, color);
    bar(0, 0, sWidth, sHeight);
    b = new Screen[8];
    createButtons();
    background();
    displayMenu();
}

void Screen::createButtons()
{
    int dy = 220, dx = 260;
    for (int x = 0; x < 5; x++)
    {
        b[x].B_setLeft(sWidth / 2 - 100);
        b[x].B_setRight(sWidth / 2 + 25);
        b[x].B_setTop(dy);
        b[x].B_setBottom(dx);
        b[x].B_setColor(RED);
        dy += 60;
        dx += 60;

        if (x == 4)
        {
            b[x].B_setLeft(5);
            b[x].B_setRight(200);
            b[x].B_setTop(10);
            b[x].B_setBottom(50);
            b[x].B_setColor(RED);
        }

        p[x] = &b[x];
    }
}

void Screen::background()
{
    initwindow(sWidth, sHeight, "Zero To Hero");
    POINT cursorPosition;
    readimagefile("image/b7.jpg", 0, 0, sWidth, sHeight);
    readimagefile("image/logo2.JPG", sWidth / 2 - 200, 25, sWidth / 2 + 200, 150);
}
void Screen::displayMenu()
{
    for (int x = 0; x < 4; x++){b[x].B_Draw();}
    

    setcolor(color);
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(p[0]->getB_Left() + 10, p[0]->getB_Top() + 10, "START");
    
    setcolor(color);
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(p[1]->getB_Left() + 10, p[1]->getB_Top() + 10, "Help");
    
    setcolor(color);
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(p[2]->getB_Left() + 10, p[2]->getB_Top() + 10, "About");
    
    setcolor(color);
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(p[3]->getB_Left() + 10, p[3]->getB_Top() + 10, "Exit");
    
    getMousePos();
}

void Screen::backToMenuButton()
{
    b[4].draw();
    setcolor(color);
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(p[4]->getLeft() + 10, p[4]->getTop() + 10, "Back to Menu");
}

void Screen::getMousePos()
{
    bool choice = 1;
    while (choice)
    {
        int x, y;
        GetCursorPos(&cursorPosition);
        x = cursorPosition.x;
        y = cursorPosition.y;

    if ((GetAsyncKeyState(VK_LBUTTON)) && (((x > p[0]->getB_Left()) && (x < p[0]->getB_Right())) && (((y > p[0]->getB_Top()) && (y < p[0]->getB_Bottom())))))
    {
     choice = 0;
    }

    if ((GetAsyncKeyState(VK_LBUTTON)) && (((x > p[1]->getB_Left()) && (x < p[1]->getB_Right())) && (((y > p[1]->getB_Top()) && (y < p[1]->getB_Bottom())))))
    {
    readimagefile("image/help.JPG", 0, 0, sWidth, sHeight);
    backToMenuButton();
    }
    if ((GetAsyncKeyState(VK_LBUTTON)) && (((x > p[2]->getB_Left()) && (x < p[2]->getB_Right())) && (((y > p[2]->getB_Top()) && (y < p[2]->getB_Bottom())))))
    {
     readimagefile("image/about.JPG", 0, 0, sWidth, sHeight);
    backToMenuButton();
    }

    if ((GetAsyncKeyState(VK_LBUTTON)) && (((x > p[3]->getB_Left()) && (x < p[3]->getB_Right())) && (((y > p[3]->getB_Top()) && (y < p[3]->getB_Bottom())))))
    {
    readimagefile("image/closing.JPG", 0, 0, sWidth, sHeight);
    delay(2000);
    readimagefile("image/credits3.JPG", 0, 0, sWidth, sHeight);
    delay(2000);

     exit(1);
    }
    if ((GetAsyncKeyState(VK_LBUTTON)) && (((x > p[4]->getB_Left()) && (x < p[4]->getB_Right())) && (((y > p[4]->getB_Top()) && (y < p[4]->getB_Bottom())))))
    {
     menu();
    }
    }
}
