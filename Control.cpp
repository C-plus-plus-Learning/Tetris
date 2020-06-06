#include "Control.h"

Control::Control(Windows windows, Mechanism mechanism) : mechanism(windows) {
    this->mechanism = mechanism;
    this->windows = windows;
}

// 加速下落
int Control::myDown(HANDLE hOut, int block[4][4], int map[21][12], int &x, int y) {
    if (mechanism.collisionDetection(block, map, x + 1, y)) {
        mechanism.clearBlock(hOut, block, x, y);
        ++x;
        return 0;
    }
    if (x < 0) {
        return 2;
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (block[i][j] == 1) {
                map[x + i][y + j] = 1;
                SetConsoleTextAttribute(hOut,
                                        FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                windows.gotoXY(hOut, 2 * (y + j), x + i);
                cout << "■";
            }
        }
    }
    return 1;
}

//左移
void Control::myLeft(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y) {
    if (mechanism.collisionDetection(block, map, x, y - 1)) {
        mechanism.clearBlock(hOut, block, x, y);
        --y;
    }
}

// 右移
void Control::myRight(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y) {
    if (mechanism.collisionDetection(block, map, x, y + 1)) {
        mechanism.clearBlock(hOut, block, x, y);
        ++y;
    }
}

// 顺时针旋转90度
void Control::myUp(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y) {
    switch (block[0][0]) {
        case 10:
            if (mechanism.collisionDetection(block01, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block01[i][j];
                    }
                }
            }
            break;
        case 11:
            if (mechanism.collisionDetection(block00, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block00[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block00, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block00[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block00, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block00[i][j];
                    }
                }
                ++y;
            } else if (mechanism.collisionDetection(block00, map, x, y - 2)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block00[i][j];
                    }
                }
                y = y - 2;
            } else if (mechanism.collisionDetection(block00, map, x, y + 2)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block00[i][j];
                    }
                }
                y = y + 2;
            }
            break;
        case 12:
            if (mechanism.collisionDetection(block03, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block03[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block03, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block03[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block03, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block03[i][j];
                    }
                }
                ++y;
            }
            break;
        case 13:
            if (mechanism.collisionDetection(block04, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block04[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block04, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block04[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block04, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block04[i][j];
                    }
                }
                ++y;
            }
            break;
        case 14:
            if (mechanism.collisionDetection(block05, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block05[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block05, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block05[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block05, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block05[i][j];
                    }
                }
                ++y;
            }
            break;
        case 15:
            if (mechanism.collisionDetection(block02, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block02[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block02, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block02[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block02, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block02[i][j];
                    }
                }
                ++y;
            }
            break;

        case 16:
            if (mechanism.collisionDetection(block07, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block07[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block07, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block07[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block07, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block07[i][j];
                    }
                }
                ++y;
            }
            break;
        case 17:
            if (mechanism.collisionDetection(block08, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block08[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block08, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block08[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block08, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block08[i][j];
                    }
                }
                ++y;
            }
            break;
        case 18:
            if (mechanism.collisionDetection(block09, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block09[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block09, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block09[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block09, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block09[i][j];
                    }
                }
                ++y;
            }
            break;
        case 19:
            if (mechanism.collisionDetection(block06, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block06[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block06, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block06[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block06, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block06[i][j];
                    }
                }
                ++y;
            }
            break;
        case 20:
            if (mechanism.collisionDetection(block11, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block11[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block11, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block11[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block11, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block11[i][j];
                    }
                }
                ++y;
            }
            break;
        case 21:
            if (mechanism.collisionDetection(block12, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block12[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block12, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block12[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block12, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block12[i][j];
                    }
                }
                ++y;
            }
            break;
        case 22:
            if (mechanism.collisionDetection(block13, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block13[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block13, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block13[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block13, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block13[i][j];
                    }
                }
                ++y;
            }
            break;
        case 23:
            if (mechanism.collisionDetection(block10, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block10[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block10, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block10[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block10, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block10[i][j];
                    }
                }
                ++y;
            }
            break;
        case 24:
            if (mechanism.collisionDetection(block15, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block15[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block15, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block15[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block15, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block15[i][j];
                    }
                }
                ++y;
            }
            break;
        case 25:
            if (mechanism.collisionDetection(block14, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block14[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block14, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block14[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block14, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block14[i][j];
                    }
                }
                ++y;
            }
            break;
        case 26:
            if (mechanism.collisionDetection(block17, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block17[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block17, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block17[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block17, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block17[i][j];
                    }
                }
                ++y;
            }
            break;
        case 27:
            if (mechanism.collisionDetection(block16, map, x, y)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block16[i][j];
                    }
                }
            } else if (mechanism.collisionDetection(block16, map, x, y - 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block16[i][j];
                    }
                }
                --y;
            } else if (mechanism.collisionDetection(block16, map, x, y + 1)) {
                mechanism.clearBlock(hOut, block, x, y);
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        block[i][j] = block16[i][j];
                    }
                }
                ++y;
            }
            break;
        default:
            break;
    }
}


