#include <iostream>
using namespace std;
#include "Stack_Sq.h"
typedef char ElemType;
int main(int argc, char const* argv[]) {
	SqStack stack;
	ElemType c, e;
	InitStack(stack);

	while ((c = getchar()) != EOF) {
		switch (c) {
			case '(':
			case '[':
			case '{':
				Push(stack, c);
				break;

			case ')':
			case ']':
			case '}':
				Pop(stack, e);

				if (e == c - 1) {
					break;
				} else {
					return 1;
				}
		}
	}

	return 0;
}
