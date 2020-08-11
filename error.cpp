#include "header/error.hpp"

Error::Error() { setHighlightColor(RED); }
int Error::getScore() { return -1; }
string Error::getTextFile(int _i) { return fileTextError[_i]; }