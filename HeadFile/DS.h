#ifndef DS_H
#define DS_H

#define OK 0
#define ERROR 1
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
//typedef int ElemType;
template <typename T> 
	void swap(T & a, T & b);
	int Print(ElemType);
	int PrintLine(ElemType);
	bool Equal(ElemType, ElemType);

#endif
