#include<iostream>
using namespace std;
#include"../HeadFile/DSF.h"
template <typename T>
void swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}
int Print(ElemType e) {
	cout << e;
	return 0;
}
int PrintLine(ElemType e) {
	cout << e << endl;
	return 0;
}
bool Equal(ElemType a, ElemType b) {
	return a == b;
}
