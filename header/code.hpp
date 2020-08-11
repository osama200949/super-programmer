#ifndef Code_H
#define Code_H

#include <fstream>
#include <graphics.h>
#include <iostream>
#include <string>

using namespace std;

class Code
{
protected:
    int x, y;
    string text;
    int color;
    int index;
    int lineIndex;
    int lineIndexError;
    int newLineIndex;
    string fileName[4];
    string *fileText;
    string *fileTextError;
    int startingLine;
    int txtColor, bkColor, hlColor;

    int width, height;

    int center(int len, int min, int max) { return (max + min - len) / 2; } // an helper function to center things
    char *toStr() const { return (char *)text.c_str(); }                    // an helper method for shorthand, so that, no need to typecast everytime pass the text to winbgi function

    int getTextTop() { return center(textheight(toStr()), top(), bottom()); } // an helper method
    int getLeftOfCharAt(int index)                                            // to get the x of character at particular index
    {
        int tx = getTextLeft();
        // get string upto the index, for calculating the width
        string s = text.substr(0, index);
        int w = textwidth((char *)s.c_str());
        return tx + w;
    }

public:
    Code(string t = "", int _x = 0, int _y = 0, int w = 100, int h = 100, int tc = BLACK, int bc = LIGHTGRAY, int hc = YELLOW);
    ~Code();
    int length() const;
    int left() const;
    int top() const;
    int right() const;
    int bottom() const;

    void displayText();
    void displayNextText();
    void draw();
    void drawHighlight(int index, int color);
    void highlight(int index);
    void unhighlight(int index);

    void setColor(int _color);
    void setText(string _t);
    void setXY(int _x, int _y);
    void setString(string newT);
    void setTextFromFile(int fileIndex);
    void setHighlightColor(int value);
    void setY(int _y);
    void setX(int _x);
    
    int getTextLeft();
    int getLineIndex();
    int getLineIndexError();
    string getString();
    string getTextFileError(int _i);
    int getX();
    int getY();
    virtual string getTextFile(int _i) {}
    virtual int getScore() {}
};

#endif