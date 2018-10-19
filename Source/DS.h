#ifndef DS_H
#define DS_H

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef double ElemType;
template <typename T>
void swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}
int Show(ElemType e) {
	std::cout << e << std::endl;
	return 0;
}
bool Equal(ElemType a, ElemType b) {
	return a == b;
}
#endif