#include <iostream>
#include "HeadFile/DS.h"
using namespace std;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
} DuLNode, *DuLinkList;
/*
list1(*)<->HeadNode<->Node1<->...<->Noden
*/
Status InitList(DuLinkList&);
Status ListInsert(DuLinkList&, int, ElemType);
Status ListDelete(DuLinkList&, int, ElemType&);
Status GetElem(DuLinkList, int, ElemType&);
Status CreateList /*Head Insert*/ (DuLinkList&, int);
Status DestroyList(DuLinkList&);
bool ListEmpty(DuLinkList);
int ListLength(DuLinkList);
//int LocateElem(DuLinkList, ElemType, bool (*)(ElemType, ElemType));
//Status PriorElem(SqList, ElemType, ElemType&);
//Status NextElem(SqList, ElemType, ElemType&);
Status ListTraverse(DuLinkList&, int (*)(ElemType));

int main() {
	DuLinkList list1 = NULL;
	ElemType e;
	InitList(list1);

	for (int i = 0; i < 100; ++i) {
		ListInsert(list1, 1, 1.0 / i);
	}

	ListDelete(list1, 1, e);
	ListTraverse(list1, Show);
	return 0;
}

Status InitList(DuLinkList& L) {
	L = (DuLinkList)malloc(sizeof(DuLNode));
	L->prior = L->next = NULL;
	return OK;
} //InitList
int ListLength(DuLinkList L) {
	int j = 0;

	while (L) {
		L = L->next;
		++j;
	}

	return j;
} //ListLength
Status ListInsert(DuLinkList& L, int i, ElemType e) {
	DuLNode* p = L;
	int j = 0;

	while (p && j < i - 1) {
		p = p->next;
		++j;
	}

	if (!p || j > i - 1) {
		return ERROR;
	}

	DuLNode* s = (DuLinkList)malloc(sizeof(DuLNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	s->next->prior = s;
	s->prior = p;
	return OK;
} //ListInsert
Status ListDelete(DuLinkList& L, int i, ElemType& e) {
	DuLinkList p = L;
	int j = 0;

	while (p->next && j < i - 1) {
		p = p->next; //j=i-1
		++j;
	}

	if (!(p->next) || j > i - 1) {
		return ERROR;
	}

	DuLinkList q = p->next;
	p->next = q->next;
	q->next->prior = p;
	e = q->data;
	free(q);
	return OK;
} //ListDelete
Status GetElem(DuLinkList L, int i, ElemType& e) {
	DuLinkList p = L;
	int j = 0;

	while (p && j < i) {
		p = p->next;
		++j;
	}

	if (!p || j > i) {
		return ERROR;
	}

	e = p->data;
	return OK;
} //GetElem
Status CreateList /*Head Insert*/ (DuLinkList& L, int n) {
	L = (DuLinkList)malloc(sizeof(DuLNode));
	L->next = NULL;
	DuLinkList p;

	for (int i = n; i > 0; --i) {
		p = (DuLinkList)malloc(sizeof(DuLNode));
		cin >> p->data;
		p->next = L->next;
		L->next->prior = p;
		p->prior = L;
		L->next = p;
	}

	return OK;
} //CreateList
Status DestroyList(DuLinkList& L) {
	DuLinkList p = L, q = L;

	do {
		q = p->next;
		free(p);
		p = q;
	} while (p);

	L = NULL;
	return OK;
} //DestroyList
bool ListEmpty(DuLinkList L) {
	return L->next == NULL;
} //ListEmpty
Status ListTraverse(DuLinkList& L, int (*func)(ElemType)) {
	DuLinkList p = L->next;

	while (p && !func(p->data)) {
		p = p->next;
	}

	if (p) {
		return ERROR;
	}

	return OK;
} //ListTraverse
