#include <iostream>
#include "HeadFile/Stack_Sq.h"
using namespace std;
int main() {
	SqStack stack;
	ElemType c, elem;
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
				Pop(stack, elem);

				if (elem == c - 1) {
					break;
				} else {
					return 1;
				}
		}
	}

	return 0;
}
