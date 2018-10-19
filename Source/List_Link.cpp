#include <iostream>
using namespace std;
#include "List_Link.h"
Status InitList(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
} //InitList
int ListLength(LinkList L) {
	int j = 0;

	while (L) {
		L = L->next;
		++j;
	}

	return j;
} //ListLength
Status ListInsert(LinkList& L, int i, ElemType e) {
	LNode* p = L;
	int j = 0;

	while (p && j < i - 1) {
		p = p->next;
		++j;
	}

	if (!p || j > i - 1) {
		return ERROR;
	}

	LNode* s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
} //ListInsert
Status ListDelete(LinkList& L, int i, ElemType& e) {
	LinkList p = L;
	int j = 0;

	while (p->next && j < i - 1) {
		p = p->next; //j=i-1
		++j;
	}

	if (!(p->next) || j > i - 1) {
		return ERROR;
	}

	LinkList q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
} //ListDelete
Status GetElem(LinkList L, int i, ElemType& e) {
	LinkList p = L;
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
Status CreateList /*Head Insert*/ (LinkList& L, int n) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LinkList p;

	for (int i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(LNode));
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}

	return OK;
} //CreateList
Status DestroyList(LinkList& L) {
	LinkList p = L, q = L;

	do {
		q = p->next;
		free(p);
		p = q;
	} while (p);

	L = NULL;
	return OK;
} //DestroyList
bool ListEmpty(LinkList L) {
	return L->next == NULL;
} //ListEmpty
Status ListTraverse(LinkList& L, int (*func)(ElemType)) {
	LinkList p = L->next;

	while (p && !func(p->data)) {
		p = p->next;
	}

	if (p) {
		return ERROR;
	}

	return OK;
} //ListTraverse
