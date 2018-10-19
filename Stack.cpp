#include <iostream>
#include "DS.h"
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;
} SqStack;
/*
	 __________________________________________________
base|_1|_2|_3|_top|__|__|______________________________|
*/
Status InitStack(SqStack&);
Status DestoryStack(SqStack&);
Status ClearStack(SqStack&);
bool StackEmpty(SqStack);
int StackLength(SqStack);
Status GetTop(SqStack S, ElemType&);
Status Push(SqStack& S, ElemType e);
Status Pop(SqStack& S, ElemType& e);
Status StackTraverse(SqStack S, int (*)(ElemType));

int main() {
	return 0;
}

Status InitStack(SqStack& stack) {
	stack.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));

	if (!stack.base)
		exit(OVERFLOW);

	stack.top = stack.base;
	stack.stacksize = STACK_INIT_SIZE;
	return OK;
} //InitStack
Status DestoryStack(SqStack& stack) {
	free(stack.base);
	stack.base = stack.top = NULL;
	stack.stacksize = 0;
	return OK;
} //DestoryStack
Status ClearStack(SqStack& stack) {
	stack.top = stack.base;
} //ClearStack
bool StackEmpty(SqStack stack) {
	return stack.top == stack.base;
} //StackEmpty
int StackLength(SqStack stack) {
	return stack.top - stack.base;
} //StackLength
Status GetTop(SqStack stack, ElemType& e) {
	if (stack.base == stack.top)
		return ERROR;

	e = *stack.top;
	return OK;
} //GetTop
Status Push(SqStack& stack, ElemType e) {
	if (stack.top - stack.base >= stack.stacksize) {
		stack.base = (ElemType*)realloc(stack.base, (stack.stacksize + STACKINCREMENT) * sizeof(ElemType));

		if (!stack.base)
			exit(OVERFLOW);

		stack.top = stack.base + stack.stacksize; //Important!!
		stack.stacksize += STACKINCREMENT;
	}

	*stack.top++ = e;
	return OK;
} //Push
Status Pop(SqStack& stack, ElemType& e) {
	if (stack.top == stack.base)
		return ERROR;

	e = *--stack.top;
	return OK;
} //Pop
Status StackTraverse(SqStack stack, int (*func)(ElemType)) {
	ElemType* p = stack.base;
	while (p < stack.top && !func(*p))
		++p;
	if (p < stack.top)
		return ERROR;
	return OK;
} //StackTraverse