#ifndef TETRIS_SCHEDULE_H
#define TETRIS_SCHEDULE_H

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include "Mechanism.cpp"

using namespace std;

class Schedule {
public:
    Schedule(Windows windows, Mechanism mechanism);
    void gameOver(HANDLE hOut, int block[4][4], int map[21][12]);
    void myStop(HANDLE hOut, int block[4][4]);
private:
    Windows windows;
    Mechanism mechanism;
};


#endif //TETRIS_SCHEDULE_H
