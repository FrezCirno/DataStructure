#include <iostream>
using namespace std;
#include "Stack_Sq.h"
void Conversion() {
	SqStack stack;
	InitStack(stack);
	int N;
	ElemType e;
	cin >> N;

	while (N) {
		Push(stack, N % 8);
		N /= 8;
	}

	while (!StackEmpty) {
		Pop(stack, e);
		cout << e;
	}

	return;
}
int main(int argc, char const* argv[]) {
	Conversion();
	return 0;
}
