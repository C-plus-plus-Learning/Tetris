#ifndef TETRIS_MECHANISM_H
#define TETRIS_MECHANISM_H

#include <ctime>
#include <iostream>
#include "Windows.h"
#include "Base.h"

using namespace std;

class Mechanism {
public:
    Mechanism(Windows windows);
    void clearBlock(HANDLE hOut, int block[4][4], int x, int y);
    void roundBlock(HANDLE hOut, int block[4][4]);
    bool collisionDetection(int block[4][4], int map[21][12], int x, int y);
    void eliminateRow(HANDLE hOut, int map[21][12], int &val, int &fraction, int &checkpoint);

private:
    Windows windows;
};


#endif //TETRIS_MECHANISM_H
