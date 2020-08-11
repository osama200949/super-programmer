#include "header/code.hpp"

Code::Code(string t, int _x, int _y, int w, int h, int tc, int bc, int hc)
    : text(t), x(_x), y(_y), width(w), height(h), txtColor(tc), bkColor(bc), hlColor(hc)
{

    index = lineIndex = lineIndexError = newLineIndex = startingLine = 0;
    string text[4] = {"clean.txt", "error.txt", "tex3,txt", "text4.txt"};
    for (int i = 0; i < 4; i++)
        fileName[i] = text[i];

    setTextFromFile(1);
    setTextFromFile(0);
}
Code::~Code()
{
    delete fileText;
    delete fileTextError;
}

int Code::getTextLeft() { return center(textwidth(toStr()), left(), right()); } // an helper method
int Code::length() const { return text.length(); }
int Code::left() const { return x; }
int Code::top() const { return y; }
int Code::right() const { return x + width; }
int Code::bottom() const { return y + height; }
void Code::setHighlightColor(int value) { hlColor = value; }
void Code::setY(int _y) { y = _y; }
void Code::setX(int _x) { x = _x; }
void Code::setXY(int _x, int _y)
{
    x = _x;
    y = _y;
}
void Code::displayText()
{
    y = y + 10;
    if (startingLine < 10)
    {
        for (int i = startingLine; i < startingLine + 8; i++)
        {
            text = fileText[i];
            settextstyle(4, HORIZ_DIR, 1);
            setcolor(color);
            outtextxy(x, y, (char *)text.c_str());
            y = y + 30;
        }
    }
    else
        return;
}

void Code::displayNextText()
{
    y = y + 10;
    if (startingLine > 7)
    {
        for (int i = startingLine; i < startingLine + 8; i++)
        {
            text = fileText[i];
            settextstyle(4, HORIZ_DIR, 1);
            setcolor(color);
            outtextxy(x, y, (char *)text.c_str());
            y = y + 30;
        }
    }
    else
        return;
}

void Code::draw()
{
    // draw the text
    setbkcolor(bkColor);
    setcolor(txtColor);
    outtextxy(getTextLeft(), getTextTop(), toStr());
}

void Code::drawHighlight(int index, int color)
{
    // get the character at the index
    char s[] = {text[index], 0}; // this a c-string. must be terminated with a null character (0)
    setbkcolor(bkColor);
    setcolor(color);
    outtextxy(getLeftOfCharAt(index), getTextTop(), s);
}
// highlight character at particular index
void Code::highlight(int index) { drawHighlight(index, hlColor); }

// highlight character at particular index
void Code::unhighlight(int index) { drawHighlight(index, bkColor); }

void Code::displayText();

void Code::displayNextText();

int Code::getX() { return x; }

int Code::getY() { return y; }

int Code::getLineIndex() { return lineIndex; }

int Code::getLineIndexError() { return lineIndexError; }

string Code::getString() { return text; }

string Code::getTextFileError(int _i) { return fileTextError[_i]; }

void Code::setXY(int _x, int _y);

void Code::setString(string newT) { text = newT; }

void Code::setColor(int _color) { color = _color; }

void Code::setText(string _t) { text = _t; }

void Code::setTextFromFile(int fileIndex)
{

    ifstream in(fileName[fileIndex]); // fileName[0] -> txt1.txt file

    int i = 0;
    string _text[300];

    if (in.is_open())
    {
        while (getline(in, _text[i]))
        {
            while (_text[i].substr(0, 1) == " ")
            {
                _text[i].replace(0, 1, "");
            }

            for (int i = 0; i < _text[i].length(); i++)
            {
                if (_text[i].substr(_text[i].length() - 1, 1) == " ")
                    _text[i].replace(_text[i].length() - 1, 1, "");
            }
            if (_text[i].length() > 50) // Manage Lines with length bigger than 50 character
            {
                string newText = _text[i].substr(51, _text[i].length());
                _text[i].replace(51, _text[i].length(), "");

                _text[i + 1] = newText;
                if (!_text[i + 1].length() > 50)
                {
                    i += 2;
                    lineIndex += 2;
                    continue;
                }
                if (_text[i + 1].length() > 50)
                {

                    string newText2 = _text[i + 1].substr(51, _text[i + 1].length());
                    _text[i + 1].replace(51, _text[i + 1].length(), "");
                    _text[i + 2] = newText2;
                    i += 3;
                    lineIndex += 3;
                    continue;
                }
            }
            if (_text[i] != "")
            {
                i++;
                lineIndex++;
            }
        }
        in.close();
    }

    else
        cout << "Unable to open file";

    if (fileIndex == 0)
    {
        if (lineIndex > 1)
        {
            lineIndex = i;
            fileText = new string[lineIndex];
        }
        else
            cout << "File can not be assigned please chooce another file" << endl;      // Test if the file is working

        for (int i = 0; i < lineIndex; i++)
            fileText[i] = _text[i];
    }
    else if (fileIndex == 1)
    {
        {
            if (lineIndex > 1)
            {
                lineIndexError = i;
                fileTextError = new string[lineIndexError];
            }
            else
                cout << "File can not be assigned please chooce another file" << endl; // Test if the file is working

            for (int i = 0; i < lineIndexError; i++)
                fileTextError[i] = _text[i];
        }
    }
}
