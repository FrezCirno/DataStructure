#include<iostream>
#include<cstdio>
#include<cstdlib>

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int Status;
typedef double ElemType;
template<typename T>
void swap(T &a, T &b) {
	T c = a;
	a = b;
	b = c;
}
