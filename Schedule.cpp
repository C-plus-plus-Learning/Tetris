#include "Schedule.h"

Schedule::Schedule(Windows *windows, Mechanism *mechanism) {
    this->windows = windows;
    this->mechanism = mechanism;
}

// 游戏结束
void Schedule::gameOver(HANDLE hOut, int block[4][4], int map[21][12]) {
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    windows->gotoXY(hOut, 9, 8);
    cout << "GAME OVER";
    windows->gotoXY(hOut, 8, 9);
    cout << "空格键：重来";
    windows->gotoXY(hOut, 8, 10);
    cout << "ESC键：退出";
    char key;
    while (true) {
        key = _getch();
        if (key == 32) {
            return;
        }
        if (key == 27) {
            exit(0);
        }
    }
}

// 游戏暂停
void Schedule::myStop(HANDLE hOut, int block[4][4]) {
    mechanism->clearBlock(hOut, block, 5, 15);
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    windows->gotoXY(hOut, 30, 7);
    cout << "游戏暂停";
    char key;
    while (true) {
        key = _getch();
        if (key == 32) {
            windows->gotoXY(hOut, 30, 7);
            cout << "        ";
            windows->printBlock(hOut, block, 5, 15);
            return;
        }
        if (key == 27) {
            exit(0);
        }
    }
}


