#include<iostream>
using namespace std;
#include"DS.h"
template <typename T>
void swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}
int Show(ElemType e) {
	cout << e << endl;
	return 0;
}
bool Equal(ElemType a, ElemType b) {
	return a == b;
}