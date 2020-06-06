#include "Windows.h"


// 移动光标
void Windows::gotoXY(HANDLE hOut, int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}

// 打印方块
void Windows::printBlock(HANDLE hOut, int block[4][4], int x, int y) {

    switch (block[0][0]) {
        case 10:
        case 11:
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
            break;
        case 12:
        case 13:
        case 14:
        case 15:
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case 16:
        case 17:
        case 18:
        case 19:
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case 20:
        case 21:
        case 22:
        case 23:
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        case 24:
        case 25:
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case 26:
        case 27:
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        case 28:
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            break;
        default:
            break;
    }
    for (int i = 0; i < 4; ++i) {
        if (i + x >= 0) {
            for (int j = 0; j < 4; ++j) {
                if (block[i][j] == 1) {

                    gotoXY(hOut, 2 * (y + j), x + i);
                    cout << "■";
                }
            }
        }
    }
}

// 初始化窗口
void Windows::initialWindow(HANDLE hOut) {
    SetConsoleTitle("俄罗斯方块");
    COORD size = {80, 25};
    SetConsoleScreenBufferSize(hOut, size);
    SMALL_RECT rc = {0, 0, 79, 24};
    SetConsoleWindowInfo(hOut, true, &rc);
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(hOut, &cursor_info);
}

// 初始化界面
void Windows::initialPrint(HANDLE hOut) {
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < 20; ++i) {
        cout << "■                    ■☆                      ☆" << endl;
    }
    gotoXY(hOut, 26, 0);
    cout << "☆☆☆☆☆☆☆☆☆☆☆";
    gotoXY(hOut, 0, 20);
    cout << "■■■■■■■■■■■■☆☆☆☆☆☆☆☆☆☆☆☆☆";
    gotoXY(hOut, 26, 1);
    cout << "分    数：      ";
    gotoXY(hOut, 26, 2);
    cout << "关    卡：      ";
    gotoXY(hOut, 26, 4);
    cout << "下一方块：";
    gotoXY(hOut, 26, 9);
    cout << "操作方法：";
    gotoXY(hOut, 30, 11);
    cout << "↑：旋转 ↓：速降";
    gotoXY(hOut, 30, 12);
    cout << "→：右移 ←：左移";
    gotoXY(hOut, 30, 13);
    cout << "空格键：开始/暂停";
    gotoXY(hOut, 30, 14);
    cout << "Esc 键：退出";
    gotoXY(hOut, 26, 16);
    cout << "关    于：";
    gotoXY(hOut, 30, 18);
    cout << "俄罗斯方块V1.0";
    gotoXY(hOut, 35, 19);
    cout << "作者：李国良";
}
