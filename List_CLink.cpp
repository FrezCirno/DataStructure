#include <iostream>
#include "HeadFile/DS.h"
using namespace std;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, *LinkList;
/*
list1(*)->HeadNode->Node1->...->Noden
			1					/
			1					/
			O-----<---<----<----
*/
Status InitList(LinkList&);
Status ListInsert(LinkList&, int, ElemType);
Status ListDelete(LinkList&, int, ElemType&);
Status GetElem(LinkList, int, ElemType&);
Status CreateList /*Head Insert*/ (LinkList&, int);
Status DestroyList(LinkList&);
bool ListEmpty(LinkList);
int ListLength(LinkList);
//int LocateElem(LinkList, ElemType, bool (*)(ElemType, ElemType));
//Status PriorElem(SqList, ElemType, ElemType&);
//Status NextElem(SqList, ElemType, ElemType&);
Status ListTraverse(LinkList&, int (*)(ElemType));

int main() {
	LinkList list1 = NULL;
	ElemType e;
	InitList(list1);

	for (int i = 0; i < 100; ++i) {
		ListInsert(list1, 1, 1.0 / i);
	}

	ListDelete(list1, 1, e);
	ListTraverse(list1, Show);
	return 0;
}

Status InitList(LinkList& list) {
	list = (LinkList)malloc(sizeof(LNode));
	list->next = list;
	return OK;
} //InitList
int ListLength(LinkList list) {
	int j = 0;
	LinkList p = list->next;
	while (p != list) {
		p = p->next;
		++j;
	} 
    return j;
} //ListLength
Status ListInsert(LinkList& list, int i, ElemType e) {
	LNode* p = list;
	int j = 0;

	while (p && j < i - 1) {
		p = p->next;
		++j;
	}

	if (!p || j > i - 1) {
		return ERROR;
	}

	{
	}

	LNode* s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
} //ListInsert
Status ListDelete(LinkList& list, int i, ElemType& e) {
	LinkList p = list;
	int j = 0;

	while (p->next && j < i - 1) {
		p = p->next; //j=i-1
		++j;
	}

	if (!(p->next) || j > i - 1) {
		return ERROR;
	}

	{
	}

	LinkList q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
} //ListDelete
Status GetElem(LinkList list, int i, ElemType& e) {
	LinkList p = list;
	int j = 0;

	while (p && j < i) {
		p = p->next;
		++j;
	}

	if (!p || j > i) {
		return ERROR;
	}

	{
		e = p->data;
	}

	return OK;
} //GetElem
Status CreateList /*Head Insert*/ (LinkList& list, int n) {
	list = (LinkList)malloc(sizeof(LNode));
	list->next = list;
	LinkList p;

	for (int i = 0; i < n; ++i) {
		p = (LinkList)malloc(sizeof(LNode));
		cin >> p->data;
		p->next = list->next;
		list->next = p;
	}

	return OK;
} //CreateList
Status DestroyList(LinkList& list) {
	LinkList p = list, q = list;

	do {
		q = p->next;
		p = q;
	} while (p);

	list = NULL;
	return OK;
} //DestroyList
bool ListEmpty(LinkList list) {
	return list->next == list;
} //ListEmpty
Status ListTraverse(LinkList& list, int (*func)(ElemType)) {
	LinkList p = list->next;
	while (p != list && !func(p->data)) {
		p = p->next;
	}
	if (p) {
		return ERROR;
	}
	return OK;
}//ListTraverse
