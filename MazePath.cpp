#include <iostream>
using namespace std;

#define MAZESIZE 10

typedef struct {
	int x;
	int y;
} PosType;
enum dir {right = 0, down, left,  up};
typedef struct {
	int ord;//order
	PosType seat;//(x,y)
	dir di;//direction
} PathNode, ElemType;
#include "HeadFile/Stack_Sq.h"
typedef int** MazeType;



PosType dirpos[4] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};


Status MazePath(MazeType maze, PosType start, PosType end) {
	SqStack stack;
	InitStack(stack);
	PosType curpos = start;
	PathNode e;
	int curstep = 1;
	bool Book[MAZESIZE][MAZESIZE] = {0};
	do {
		if(!maze[curpos.x][curpos.y] && !Book[curpos.x][curpos.y]) { //可通
			Book[curpos.x][curpos.y] = 1;//走过
			e.ord = curstep;
			e.seat = curpos;
			e.di = (enum dir)0;
			Push(stack, e);
			if(curpos == end)return (TRUE);
			curpos += dirpos[e.di];
			curstep++;
		} else {
			if(!StackEmpty(stack)) {
				Pop(stack, e);
				while(e.di == 4 && !StackEmpty(stack)) {
					Book[pos.x][pos.y] = 1;
					Pop(stack, e);
				}
				if(e.di < 4) {
					e.di++;
					Push(stack, e);
					curpos = e.seat + dirpos[e.di];
				}
			}
		}
	} while(!StackEmpty(stack));
	return FALSE;
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
	MazePath(maze, s, e);
	return 0;
}
