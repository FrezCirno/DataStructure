#include <iostream>
using namespace std;

#define MAZESIZE 10

typedef struct {
	int x;
	int y;
} PosType;
typedef struct {
	int ord;	  //order
	PosType pos; //(x,y)
	dir di;		  //direction
} PathNode, ElemType;
#include "HeadFile/Stack_Sq.h"
typedef int MazeType[MAZESIZE][MAZESIZE];

enum dir {
	right = 0,
	down,
	left,
	up
};
PosType dirpos[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

Status MazePath(MazeType maze, PosType start, PosType end, SqStack path) {
	PosType curpos = start;
	PathNode now;
	int curstep = 1;
	bool Book[MAZESIZE][MAZESIZE] = {0};

	do {
		if (!maze[curpos.x][curpos.y] && !Book[curpos.x][curpos.y]) {
			//可通且没走过
			Book[curpos.x][curpos.y] = 1; //标记
			now.ord = curstep;
			now.pos = curpos;
			now.di = (enum dir)::right;
			Push(path, now); //压栈

			if (curpos.x == end.x && curpos.y == end.y) {
				return (TRUE);    //判断
			}

			curpos.x += dirpos[now.di][0];
			curpos.y += dirpos[now.di][1];
			curstep++; //走到下一步
		} else {
			//不可通或走过
			if (!StackEmpty(path)) {
				//还没退回起点
				do {
					Pop(path, now);				  //后退一步
					Book[now.pos.x][now.pos.y] = 1; //标记不可通
				} while (now.di == (enum dir)::up && !StackEmpty(path));//如果上一步是向上走的
				//不是向上走的或栈已空
				if (now.di < (enum dir)::up) {//还没探索过
					now.di++;//下一方向
					Push(path, now);
					curpos.x = now.pos.x + dirpos[now.di][0];
                    curpos.y = now.pos.y + dirpos[now.di][1];
				}
			}
		}
	} while (!StackEmpty(path));

	return FALSE;
}
int showpath(PathNode n) {
    cout << n.ord << " " << n.pos.x << " " << n.pos.y << endl;
    return 0;
}
int main() {
	int maze[MAZESIZE][MAZESIZE] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	PosType s = {1, 1}, e = {8, 8};
	SqStack stack;
	InitStack(stack);
	MazePath(maze, s, e, stack);
    StackTraverse(stack, showpath);
	return 0;
}
