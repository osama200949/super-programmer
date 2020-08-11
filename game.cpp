#include "header/game.hpp"

Game::Game()
{
    screenWidth = getmaxwidth();
    screenHeight = getmaxheight();
}

void Game::start()
{

    s.setColor(WHITE);
    s.setScreen(screenWidth, screenHeight);
    s.menu();
    s = Screen(0, 0, screenWidth - 200, 400, 0, 0, BLUE);
    s.setScreen(screenWidth, screenHeight);
    s.setDefaultPosition();
    s.setX(s.getInitialX());
    s.setY(s.getInitialY());
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    setfillstyle(SOLID_FILL, BLUE);
    bar(0, 0, screenWidth, screenHeight);
    s.draw();

    Clean cleanCode; // Code to type
    Error errorCode;
    Code *currentCode = &cleanCode;

    int charIndex, lineIndex, errorLineIndex, tempError, spaceLines;
    charIndex = lineIndex = errorLineIndex = tempError = spaceLines = 0;
    int xPosition, yPosition;
    int MAXLINES = 4;
    int *currentLineIndex = &lineIndex;
    int newLineIndex = 2;
    int startError = 2;
    int endError = 5;
    char key = 0;
    bool error, endOfGame, nextLine;
    error = endOfGame = nextLine = false;
    int const MAX_MiSTAKES = 5000;

    while (key != 27)
    {
        if (lineIndex + tempError >= endError) // Check if the error lines end
        {
            currentCode = &cleanCode;
            currentLineIndex = &newLineIndex;
            error = false;
            goto skiperror;
        }

        if (lineIndex >= startError && lineIndex <= endError) //Generate errors
        {
            currentCode = &errorCode;
            currentLineIndex = &errorLineIndex;
            error = true;
            if (errorLineIndex > tempError)
            {
                lineIndex++;
                tempError++;
            }
        }
        else
        {
            currentCode = &cleanCode;
            currentLineIndex = &lineIndex;
            error = false;
        }
    skiperror:

        xPosition = s.getX() + 800; // txt position

        s.move();
        s.displayScore();

        if (MAXLINES >= 1) //Ending of the Game
        {
            for (int i = 0; i < MAXLINES; i++)
            {
                currentCode->setString(currentCode->getTextFile(*currentLineIndex + i));
                currentCode->setXY(xPosition, s.getY() + spaceLines);
                currentCode->draw();
                spaceLines += 50;
            }
        }
        spaceLines = 0;
        currentCode->setString(currentCode->getTextFile(*currentLineIndex));
        currentCode->setXY(xPosition, s.getY() + spaceLines);
        currentCode->highlight(charIndex);

        if (endOfGame)
        {
            (*currentLineIndex)++;
            charIndex = 0;
            MAXLINES -= 1;
            endOfGame = false;
        }
        else if (nextLine)
        {
            (*currentLineIndex)++;
            charIndex = 0;
            nextLine = false;
        }

        if (kbhit())
        {

            key = getch();
            if (key == currentCode->getString()[charIndex])
            {
                currentCode->highlight(charIndex);
                charIndex++;
                s.setScore(currentCode->getScore());
            }

            else{s.setMistake(1);}

            if (!error)
            {
                if ((charIndex >= currentCode->getString().length() && key == 13)) //|| (error && key == 13))
                {

                    if (*currentLineIndex + MAXLINES >= currentCode->getLineIndex()) {endOfGame = true;}
                        
                    else
                    {
                        nextLine = true;
                        s.setMistake(-1);
                    }
                }
            }
            if (error)
            {
                if (key == 13)
                {
                    nextLine = true;
                    s.setMistake(-1);
                }
            }

        } // kbhit
        
        if (s.getBottom() < 0) {s.getNextRectangle();}  // getNextRectangle

        if (*currentLineIndex >= currentCode->getLineIndex() || s.getMistake() == MAX_MiSTAKES) // You win celebration, or game over
        {
            if (s.getMistake() == MAX_MiSTAKES) // Game over
            {
                s.gameOver();
                delay(200);
                getch();
                start();
            }
                s.celebration(); // Winning  celebration
                delay(200);
                getch();
                start();
        }

        delay(50);
    } // while
} // Game::start()
