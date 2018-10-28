#ifndef LIST_SLINK_H
#define LIST_SLINK_H
#include "DS.h"
#define MAXSIZE 1000
typedef struct {
	ElemType data;
	int cur;
} Component[MAXSIZE];
typedef int SLinkList;
/*
Component: space[0]--space[1]--...--space[MAXSIZE-1]

SLinkList(==int): list->space[list]->space[space[list].cur]->...
*/
Status InitSpace(Component&);
Status InitList(Component, SLinkList);
Status InsertElem(Component&, SLinkList, int, ElemType);
Status DeleteElem(Component&, SLinkList, int, ElemType&);
int LocateElem(Component, SLinkList, ElemType, bool (*)(ElemType, ElemType));
Status GetElem(Component, SLinkList, int, ElemType);
Status ListTraverse(Component, SLinkList, int (*)(ElemType));
int ListLength(Component);
bool ListEmpty(Component, SLinkList);
int Malloc(Component&);
void Free(Component&, int);
//Status PriorElem(Component H, ElemType cur_e, ElemType *pre_e);
//Status NextElem(Component H, ElemType cur_e, ElemType *next_e);

#endif