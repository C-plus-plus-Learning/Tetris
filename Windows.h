#ifndef TETRIS_WINDOWS_H
#define TETRIS_WINDOWS_H

#include "Windows.h"
#include <iostream>
#include <windows.h>

using namespace std;

class Windows {
public:
    Windows() = default;
    void gotoXY(HANDLE hOut, int x, int y);
    void printBlock(HANDLE hOut, int block[4][4], int x, int y);
    void initialWindow(HANDLE hOut);
    void initialPrint(HANDLE hOut);
};


#endif //TETRIS_WINDOWS_H
