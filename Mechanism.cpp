#include "Mechanism.h"

Mechanism::Mechanism(Windows *windows) {
    this->windows = windows;
}

// 消除方块
void Mechanism::clearBlock(HANDLE hOut, int block[4][4], int x, int y) {
    for (int i = 0; i < 4; ++i) {
        if (i + x >= 0) {
            for (int j = 0; j < 4; ++j) {
                if (block[i][j] == 1) {
                    windows->gotoXY(hOut, 2 * (y + j), x + i);
                    cout << "  ";
                }
            }
        }
    }
}

void change(int block[4][4], List list) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            block[i][j] = list.lists[i][j];
        }
    }
}

// 随机生成方块并打印到下一个方块位置
void Mechanism::roundBlock(HANDLE hOut, int block[4][4]) {
    clearBlock(hOut, block, 5, 15);
    switch (rand() % 19) {
        case 0:
            change(block, shape[0]);
            break;
        case 1:
            change(block, shape[1]);
            break;
        case 2:
            change(block, shape[2]);
            break;
        case 3:
            change(block, shape[3]);
            break;
        case 4:
            change(block, shape[4]);
            break;
        case 5:
            change(block, shape[5]);
            break;
        case 6:
            change(block, shape[6]);
            break;
        case 7:
            change(block, shape[7]);
            break;
        case 8:
            change(block, shape[8]);
            break;
        case 9:
            change(block, shape[9]);
            break;
        case 10:
            change(block, shape[10]);
            break;
        case 11:
            change(block, shape[11]);
            break;
        case 12:
            change(block, shape[12]);
            break;
        case 13:
            change(block, shape[13]);
            break;
        case 14:
            change(block, shape[14]);
            break;
        case 15:
            change(block, shape[15]);
            break;
        case 16:
            change(block, shape[16]);
            break;
        case 17:
            change(block, shape[17]);
            break;
        case 18:
            change(block, shape[18]);
            break;
        default:
            break;
    }
    windows->printBlock(hOut, block, 5, 15);
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
void Mechanism::eliminateRow(HANDLE hOut, int map[21][12], int &speed, int &score, int &checkpoint) {
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    for (int i = 19; i >= 0; --i) {
        int x = 0;
        for (int j = 1; j < 11; ++j) {
            x += map[i][j];
        }
        if (x == 10) {
            score += 100;
            if (speed > 1 && score / 1000 + 1 != checkpoint) {
                checkpoint = score / 1000 + 1;
                speed -= 5;
            }
            for (int m = i; m > 0; --m) {
                for (int n = 1; n < 11; ++n) {
                    map[m][n] = map[m - 1][n];
                    windows->gotoXY(hOut, 2 * n, m);
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
    windows->gotoXY(hOut, 36, 1);
    cout << score;
    windows->gotoXY(hOut, 36, 2);
    cout << checkpoint;
}

