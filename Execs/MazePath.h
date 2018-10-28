#define MAZESIZE 10
typedef struct {
	int x;
	int y;
} PosType;
typedef struct {
	int ord;	//order
	PosType pos;//(x,y)
	int di;		//direction
} PathNode;
typedef PathNode ElemType;

typedef int MazeType[MAZESIZE][MAZESIZE];
int dirpos[4][2] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};
