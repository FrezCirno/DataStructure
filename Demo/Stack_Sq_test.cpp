#include <iostream>
using namespace std;
#include"../HeadFile/Stack_Sq.h"
int main() {
	SqStack stack1;
	InitStack(stack1);
	cout << "Empty=" << StackEmpty(stack1) << endl;
	ElemType e;
	cout << (Push(stack1, 1.0) == OK ? "Push Success" : "Push Failed");
	StackTraverse(stack1, Print);
	cout << endl;
	cout << (Push(stack1, 2.0) == OK ? "Push Success" : "Push Failed");
	StackTraverse(stack1, Print);
	cout << endl;
	cout << (Push(stack1, 3.0) == OK ? "Push Success" : "Push Failed");
	StackTraverse(stack1, Print);
	cout << endl;
	cout << (Pop(stack1, e) == OK ? "Pop Success" : "Pop Failed");
	StackTraverse(stack1, Print);
	cout << endl;
	cout << (Pop(stack1, e) == OK ? "Pop Success" : "Pop Failed");
	StackTraverse(stack1, Print);
	cout << endl;
	cout << (Pop(stack1, e) == OK ? "Pop Success" : "Pop Failed");
	StackTraverse(stack1, Print);
	cout << endl;
	cout << (Pop(stack1, e) == OK ? "Pop Success" : "Pop Failed");
	StackTraverse(stack1, Print);
	return 0;
}
