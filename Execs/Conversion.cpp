#include <iostream>
using namespace std;
typedef int ElemType;
#include "Stack_Sq.h"
void Conversion() {
	SqStack stack;
	ElemType e;
	InitStack(stack);
	int N;
	cin >> N;
	while (N) {
		Push(stack, N % 8);
		N /= 8;
	}
	while(!StackEmpty(stack)) {
		Pop(stack, e);
		cout << e;
	}
	return;
}
int main(int argc, char const* argv[]) {
	Conversion();
	return 0;
}
