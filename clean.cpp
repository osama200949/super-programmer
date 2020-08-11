#include "header/clean.hpp"

Clean::Clean() { setHighlightColor(YELLOW); }
int Clean::getScore() { return 1; }
string Clean::getTextFile(int _i) { return fileText[_i]; }