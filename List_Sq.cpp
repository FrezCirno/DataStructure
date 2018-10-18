#include<iostream>
#include "DS.h"
using namespace std;
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

int main() {
	SqList list1, list2;
	InitList(list1);
	InitList(list2);
	for(int i = 1; i < 101; ++i)
		ListInsert(list1, 1, 1.0 / i);
	for(int i = 1; i < 101; ++i)
		ListInsert(list2, 1, -1.0 / i);
	Union(list1, list2);
	ListTraverse(list1, Show);
	cout << ListLength(list1) << endl;
	return 0;
}


Status InitList(SqList &L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem)exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//InitList
Status DestroyList(SqList& L) {
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}//DestroyList
Status ClearList(SqList& L) {
	L.length = 0;
	return OK;
}//ClearList
bool ListEmpty(SqList L) {
	return (L.length == 0);
}//ListEmpty
int ListLength(SqList L) {
	return L.length;
}//ListLength
Status GetElem(SqList L, int i, ElemType& e) {
	if(i < 1 || i > L.length)return ERROR;
	e = L.elem[i - 1];
	return OK;
}
int LocateElem(SqList L, ElemType e, bool(*compare)(ElemType, ElemType)) {
	for (ElemType* p = L.elem; p < L.elem + L.length - 1; ++p)
		if(compare(*p, e))
			return p - L.elem + 1;
	return 0;
}//LocateElem
Status PriorElem(SqList L, ElemType cur_e, ElemType& pre_e) {
	if (L.length <= 1)return ERROR;
	for (ElemType* p = L.elem + 1; p < L.elem + L.length - 1; ++p)
		if (*p == cur_e) {
			pre_e = *(p - 1);
			return OK;
		}
	return 0;
}//PriorElem
Status NextElem(SqList L, ElemType cur_e, ElemType& next_e) {
	if (L.length <= 1)return ERROR;
	for (ElemType* p = L.elem; p < L.elem + L.length - 2; ++p)
		if (*p == cur_e) {
			next_e = *(p + 1);
			return OK;
		}
	return 0;
}//NextElem
Status ListInsert(SqList &L, int i, ElemType e) {
	if (i < 1 || i > L.length + 1)return ERROR;
	if (L.length >= L.listsize) {
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit (OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	for (ElemType* p = L.elem + L.length; p > L.elem + i - 1; --p)
		*p = *(p - 1);
	*(L.elem + i - 1) = e;
	++L.length;
	return OK;
}//ListInsert
Status ListDelete(SqList& L, int i, ElemType& e) {
	if(i < 1 || i > L.length)return ERROR;
	ElemType* p = L.elem + i - 1;
	e = *p;
	for(++p; p < L.elem + L.length; ++p)
		*(p - 1) = *p;
	--L.length;
	return OK;
}//ListDelete
Status ListTraverse(SqList& L, int(*func)(ElemType e)) {
	ElemType* p = L.elem;
	while(p < L.elem + L.length && !func(*p))
		++p;
	if(p < L.elem + L.length)return ERROR;
	return OK;
}//ListTraverse
Status Union(SqList& La, SqList Lb) {
	int La_len = ListLength(La), Lb_len = ListLength(Lb);
	ElemType e;
	for(int i = 1; i <= Lb_len; ++i) {
		GetElem(Lb, i, e);
		if(!LocateElem(La, e, Equal))ListInsert(La, ++La_len, e);
	}
	return OK;
}//Union
Status MergeList(SqList La, SqList Lb, SqList& Lc) {
	int La_len = ListLength(La), Lb_len = ListLength(Lb);
	int i = 1, j = 1, k = 0;
	ElemType ai, bj;
	while ((i < La_len) && (j < Lb_len)) {
		GetElem(La, i, ai);
		GetElem(Lb, j, bj);
		if (ai <= bj) {
			ListInsert(Lc, ++k, ai);
			++i;
		} else {
			ListInsert(Lc, ++k, bj);
			++j;
		}
	}
	while (i <= La_len) {
		GetElem(La, i++, ai);
		ListInsert(Lc, ++k, ai);
	}
	while (j <= Lb_len) {
		GetElem(Lb, j++, bj);
		ListInsert(Lc, ++k, bj);
	}
	return OK;
}//MergeList


