#include "Mechanism.h"

Mechanism::Mechanism(Windows windows) {
    this->windows = windows;
}

// 消除方块
void Mechanism::clearBlock(HANDLE hOut, int block[4][4], int x, int y) {
    for (int i = 0; i < 4; ++i) {
        if (i + x >= 0) {
            for (int j = 0; j < 4; ++j) {
                if (block[i][j] == 1) {
                    windows.gotoXY(hOut, 2 * (y + j), x + i);
                    cout << "  ";
                }
            }
        }
    }
}

void change(int block[4][4], int replace[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            block[i][j] = replace[i][j];
        }
    }
}

// 随机生成方块并打印到下一个方块位置
void Mechanism::roundBlock(HANDLE hOut, int block[4][4]) {
    clearBlock(hOut, block, 5, 15);
    switch (rand() % 19) {
        case 0:
            change(block, block00);
            break;
        case 1:
            change(block, block01);
            break;
        case 2:
            change(block, block02);
            break;
        case 3:
            change(block, block03);
            break;
        case 4:
            change(block, block04);
            break;
        case 5:
            change(block, block05);
            break;
        case 6:
            change(block, block06);
            break;
        case 7:
            change(block, block07);
            break;
        case 8:
            change(block, block08);
            break;
        case 9:
            change(block, block09);
            break;
        case 10:
            change(block, block10);
            break;
        case 11:
            change(block, block11);
            break;
        case 12:
            change(block, block12);
            break;
        case 13:
            change(block, block13);
            break;
        case 14:
            change(block, block14);
            break;
        case 15:
            change(block, block15);
            break;
        case 16:
            change(block, block16);
            break;
        case 17:
            change(block, block17);
            break;
        case 18:
            change(block, block18);
            break;
        default:
            break;
    }
    windows.printBlock(hOut, block, 5, 15);
}

// 检测碰撞
bool Mechanism::collisionDetection(int block[4][4], int map[21][12], int x, int y) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (x + i >= 0 && y + j >= 0 && map[x + i][y + j] == 1 && block[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

// 判断是否能消行并更新分值
void Mechanism::eliminateRow(HANDLE hOut, int map[21][12], int &val, int &fraction, int &checkpoint) {
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    for (int i = 19; i >= 0; --i) {
        int x = 0;
        for (int j = 1; j < 11; ++j) {
            x += map[i][j];
        }
        if (x == 10) {
            fraction += 100;
            if (val > 1 && fraction / 1000 + 1 != checkpoint) {
                checkpoint = fraction / 1000 + 1;
                val -= 5;
            }
            for (int m = i; m > 0; --m) {
                for (int n = 1; n < 11; ++n) {
                    map[m][n] = map[m - 1][n];
                    windows.gotoXY(hOut, 2 * n, m);
                    if (map[m][n] == 1) {
                        cout << "■";
                    } else {
                        cout << "  ";
                    }
                }
            }
            ++i;
        }
    }
    windows.gotoXY(hOut, 36, 1);
    cout << fraction;
    windows.gotoXY(hOut, 36, 2);
    cout << checkpoint;
}

