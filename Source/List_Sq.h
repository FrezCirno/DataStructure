#ifndef LIST_SQ_H
#define LIST_SQ_H
#include "DS.h"
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef struct {
	ElemType* elem;
	int length;
	int listsize;
} SqList;
Status InitList(SqList&);
Status DestroyList(SqList&);
Status ClearList(SqList&);
bool ListEmpty(SqList);
int ListLength(SqList);
Status GetElem(SqList, int, ElemType&);
int LocateElem(SqList, ElemType, bool (*)(ElemType, ElemType));
Status PriorElem(SqList, ElemType, ElemType&);
Status NextElem(SqList, ElemType, ElemType&);
Status ListInsert(SqList&, int, ElemType);//1<=i<=L.length
Status ListDelete(SqList&, int, ElemType&);//1<=i<=L.length
Status ListTraverse(SqList&, int(*)(ElemType));
Status Union(SqList&, SqList);
Status MergeList(SqList, SqList, SqList&);
#endif