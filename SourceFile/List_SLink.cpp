#include <iostream>
#include "HeadFile/List_SLink.h"
using namespace std;


Status InitSpace(Component& space) {
	for (int i = 0; i < MAXSIZE - 1; ++i)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
	return OK;
} //InitSpace
Status InitList(Component& space, SLinkList list) {
	list = Malloc(space);
	space[list].cur = 0;
	return OK;
} //InitList

int Malloc(Component& space) {
	int i = space[0].cur;
	if (i)
		space[0].cur = space[i].cur;
	return i;
} //Malloc
void Free(Component& space, int k) {
	space[k].cur = space[0].cur;
	space[0].cur = k;
} //Free

int LocateElem(Component space, SLinkList list, ElemType e, bool (*compare)(ElemType, ElemType)) {
	int j = 1;
	list = space[list].cur;
	while (list) {
		if (compare(space[list].data, e))
			return j;
		list = space[list].cur;
		++j;
	}
	return 0;
}//LocateElem
Status GetElem(Component space, SLinkList list, int i, ElemType& e) {
	int j = 0;
	while (list && j < i) {
		list = space[list].cur;
		++j;
	}
	if (!list || j < i)
		return ERROR;
	e = space[list].data;
	return OK;
} //GetElem

Status InsertElem(Component& Space, SLinkList list, int i, ElemType e) {
	int p = list;
	int j = 0;
	while (p && j < i - 1) {
		p = Space[p].cur;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	int n = Malloc(Space);
	Space[n].data = e;
	Space[n].cur = Space[p].cur;
	Space[p].cur = n;
	return OK;
} //InsertElem
Status DeleteElem(Component& space, SLinkList list, int i, ElemType e) {
	int p = list;
	int j = 0;
	while (p && j < i - 1) {
		p = space[p].cur;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	SLinkList n = space[p].cur;
	e = space[n].data;
	Free(space, n);
	space[p].cur = space[n].cur;
	return OK;
} //DeleteElem

bool ListEmpty(Component space, SLinkList list) {
	return space[list].cur == 0;
} //ListEmpty
int ListLength(Component& space, SLinkList list) {
	int j = 0;
	while (list) {
		list = space[list].cur;
		++j;
	}
	return j;
} //ListLength

Status ListTraverse(Component space, SLinkList list, int (*func)(ElemType e)) {
	while (list && !func(space[list].data))
		list = space[list].cur;
	if (list)
		return ERROR;
	return OK;
} //ListTraverse