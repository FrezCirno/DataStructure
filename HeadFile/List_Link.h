#ifndef LIST_LINK_H
#define LIST_LINK_H
#include "DS.h"
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, *LinkList;
/*
list1(*)->HeadNode->Node1->...->Noden
*/
Status InitList(LinkList&);
Status ListInsert(LinkList&, int, ElemType);
Status ListDelete(LinkList&, int, ElemType&);
Status GetElem(LinkList, int, ElemType&);
Status CreateList(LinkList&, int); /*Head Insert*/
Status DestroyList(LinkList&);
bool ListEmpty(LinkList);
int ListLength(LinkList);
//int LocateElem(LinkList, ElemType, bool (*)(ElemType, ElemType));
//Status PriorElem(SqList, ElemType, ElemType&);
//Status NextElem(SqList, ElemType, ElemType&);
Status ListTraverse(LinkList&, void (*)(ElemType));
#endif