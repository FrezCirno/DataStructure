#include <iostream>
using namespace std;
#include "HeadFile/Stack_Sq.h"
int main(int argc, char const* argv[]) {
	SqStack stack;
	ElemType c, elem;
	InitStack(stack);

	while ((c = getchar()) != EOF && c != '\n') {
		switch (c) {
			case '#':
				Pop(stack, elem);

			case '@':
				ClearStack(stack);

			default:
				Push(stack, c);
		}
	}

	StackTraverse(stack, Show);
	cout << endl;
	return 0;
}
