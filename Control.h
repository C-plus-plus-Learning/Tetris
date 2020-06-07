#ifndef TETRIS_CONTROL_H
#define TETRIS_CONTROL_H

#include "Windows.h"
#include "Mechanism.h"

class Control {
public:
    Control(Windows *windows, Mechanism *mechanism);
    int myDown(HANDLE hOut, int block[4][4], int map[21][12], int &x, int y);
    void myLeft(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);
    void myRight(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);
    void myUp(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);
private:
    Windows *windows;
    Mechanism *mechanism;
};


#endif //TETRIS_CONTROL_H
