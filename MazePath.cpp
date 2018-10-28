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
			//��ͨ��û�߹�
			Book[curpos.x][curpos.y] = 1; //���
			now.ord = curstep;
			now.pos = curpos;
			now.di = (enum dir)::right;
			Push(path, now); //ѹջ

			if (curpos.x == end.x && curpos.y == end.y) {
				return (TRUE);    //�ж�
			}

			curpos.x += dirpos[now.di][0];
			curpos.y += dirpos[now.di][1];
			curstep++; //�ߵ���һ��
		} else {
			//����ͨ���߹�
			if (!StackEmpty(path)) {
				//��û�˻����
				do {
					Pop(path, now);				  //����һ��
					Book[now.pos.x][now.pos.y] = 1; //��ǲ���ͨ
				} while (now.di == (enum dir)::up && !StackEmpty(path));//�����һ���������ߵ�
				//���������ߵĻ�ջ�ѿ�
				if (now.di < (enum dir)::up) {//��û̽����
					now.di++;//��һ����
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
