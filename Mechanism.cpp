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

void Mechanism::roundBlock(HANDLE hOut, int block[4][4]) {
    clearBlock(hOut, block, 5, 15);
    switch (rand() % 19) {
        case 0:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block00[i][j];
                }
            }
            break;
        case 1:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block01[i][j];
                }
            }
            break;
        case 2:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block02[i][j];
                }
            }
            break;
        case 3:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block03[i][j];
                }
            }
            break;
        case 4:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block04[i][j];
                }
            }
            break;
        case 5:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block05[i][j];
                }
            }
            break;
        case 6:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block06[i][j];
                }
            }
            break;
        case 7:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block07[i][j];
                }
            }
            break;
        case 8:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block08[i][j];
                }
            }
            break;
        case 9:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block09[i][j];
                }
            }
            break;
        case 10:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block10[i][j];
                }
            }
            break;
        case 11:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block11[i][j];
                }
            }
            break;
        case 12:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block12[i][j];
                }
            }
            break;
        case 13:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block13[i][j];
                }
            }
            break;
        case 14:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block14[i][j];
                }
            }
            break;
        case 15:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block15[i][j];
                }
            }
            break;
        case 16:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block16[i][j];
                }
            }
            break;
        case 17:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block17[i][j];
                }
            }
            break;
        case 18:
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    block[i][j] = block18[i][j];
                }
            }
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

