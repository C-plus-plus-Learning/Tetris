#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

extern int block00[4][4];
extern int block01[4][4];
extern int block02[4][4];
extern int block03[4][4];
extern int block04[4][4];
extern int block05[4][4];
extern int block06[4][4];
extern int block07[4][4];
extern int block08[4][4];
extern int block09[4][4];
extern int block10[4][4];
extern int block11[4][4];
extern int block12[4][4];
extern int block13[4][4];
extern int block14[4][4];
extern int block15[4][4];
extern int block16[4][4];
extern int block17[4][4];
extern int block18[4][4];

struct List {
    int lists[4][4];
};

extern vector<List> shape;
extern int map[21][12];

// 候选区的方块
extern int blockA[4][4];
// 下落中的方块
extern int blockB[4][4];
// 方块左上角的坐标
extern int positionX, positionY;
// 检查方块还能不能下落
extern bool check;
// 用来存储按键
extern char key;
// 用来控制下落速度
extern int speed;
// 用来存储得分
extern int score;
// 用来存储关卡
extern int checkpoint;
extern int times;

extern void init();