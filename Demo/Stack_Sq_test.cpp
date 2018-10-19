#include <iostream>
using namespace std;
#include"Stack_Sq.h"
int main() {
	SqStack stack1;
	InitStack(stack1);
	cout << "Empty=" << StackEmpty(stack1) << endl;

	for (int i = 0; i < 100; ++i)
		Push(stack1, 1.0 / i);

	StackTraverse(stack1, Show);
	ElemType e;
	GetTop(stack1, e);
	cout << e;
	return 0;
}