#include "Windows.h"


// �ƶ����
void Windows::gotoXY(HANDLE hOut, int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}

// ��ӡ����
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
                    cout << "��";
                }
            }
        }
    }
}

// ��ʼ������
void Windows::initialWindow(HANDLE hOut) {
    SetConsoleTitle("����˹����");
    // ������Ļ��������С
    COORD size = {10, 25};
    SetConsoleScreenBufferSize(hOut, size);
    // ���ô��ڴ�С
    SMALL_RECT rc = {0, 0, 79, 24};
    SetConsoleWindowInfo(hOut, true, &rc);
    // ���ù���С
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(hOut, &cursor_info);
}

// ��ʼ������
void Windows::initialPrint(HANDLE hOut) {
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < 20; ++i) {
        cout << "��                    ����                      ��" << endl;
    }
    gotoXY(hOut, 26, 0);
    cout << "������������";
    gotoXY(hOut, 0, 20);
    cout << "��������������������������������������";
    gotoXY(hOut, 26, 1);
    cout << "��    ����      ";
    gotoXY(hOut, 26, 2);
    cout << "��    ����      ";
    gotoXY(hOut, 26, 4);
    cout << "��һ���飺";
    gotoXY(hOut, 26, 9);
    cout << "����������";
    gotoXY(hOut, 30, 11);
    cout << "������ת �����ٽ�";
    gotoXY(hOut, 30, 12);
    cout << "�������� ��������";
    gotoXY(hOut, 30, 13);
    cout << "�ո������ʼ/��ͣ";
    gotoXY(hOut, 30, 14);
    cout << "Esc �����˳�";
    gotoXY(hOut, 26, 16);
    cout << "��    �ڣ�";
    gotoXY(hOut, 30, 18);
    cout << "����˹����";
    gotoXY(hOut, 35, 19);
}
