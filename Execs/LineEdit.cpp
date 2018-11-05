#include <iostream>
using namespace std;
typedef char ElemType;
#include "Stack_Sq.h"
#include "DSF.h"
int main(int argc, char const* argv[]) {
	SqStack stack;
	ElemType c, elem;
	InitStack(stack);
	while ((c = getchar()) != EOF) {
		switch (c) {
			case '#':
				Pop(stack, elem);
				break;
			case '\n':
				StackTraverse(stack, Print);
				cout << c;
			case '@':
				ClearStack(stack);
				break;
			default:
				Push(stack, c);
				break;
		}
	}
	return 0;
}
