#include <iostream>
typedef char ElemType;
#include "Stack_Sq.h"
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
				if(Pop(stack, elem) == OK && elem == '(')break;
				else return ERROR;
			case ']':
				if(Pop(stack, elem) == OK && elem == '[')break;
				else return ERROR;
			case '}':
				if(Pop(stack, elem) == OK && elem == '{')break;
				else return ERROR;
			default:
				;
		}
	}
	if(!StackEmpty(stack))return ERROR;
	return 0;
}
