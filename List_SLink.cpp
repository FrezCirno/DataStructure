#include<iostream>
#include"DS.h"
using namespace std;

#define MAXSIZE 1000
typedef struct {
	ElemType data;
	int  cur;
} Component[MAXSIZE];
typedef int SLinkList;
/*
space[0]--space[1]--...--space[MAXSIZE-1]

list(int)->space[list]->space[space[list].cur]->...
*/
Status InitSpace(Component&);
Status InitList(Component, SLinkList);
Status InsertElem(Component&, SLinkList, int, ElemType);
Status DeleteElem(Component&, SLinkList, int, ElemType&);
int LocateElem(Component, SLinkList, ElemType, bool (*)(ElemType, ElemType));
Status GetElem(Component, SLinkList, int, ElemType);
Status ListTraverse(Component, SLinkList, int(*)(ElemType));
int ListLength(Component);
bool ListEmpty(Component, SLinkList);
int Malloc(Component&);
void Free(Component&, int);
//Status PriorElem(Component H, ElemType cur_e, ElemType *pre_e);
//Status NextElem(Component H, ElemType cur_e, ElemType *next_e);

int main() {
	Component space;
	InitSpace(space);
	SLinkList list;
	InitList(space, list);
	for (int i = 0; i < 100; ++i) {
		InsertElem(space, list, 1, i);
	}
	ListTraverse(space, list, Show);
	system("pause");
	return 0;
}

int LocateElem(Component space, SLinkList list, ElemType e, bool (*compare)(ElemType, ElemType)) {
	int j = 1;
    list = space[list].cur;
    while (list) {
        if (compare(space[list].data, e))  return j;
        list = space[list].cur;
        ++j;
    }
    return 0;
}//LocateElem
Status InitSpace(Component& space) {
	for (int i = 0; i < MAXSIZE - 1; ++i)space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
	return OK;
}//InitSpace
int Malloc(Component& space) {
	int i = space[0].cur;
	if (i) space[0].cur = space[i].cur;
	return i;
}//Malloc
void Free(Component& space, int k) {
	space[k].cur = space[0].cur;
	space[0].cur = k;
}//Free
//void Difference(Component& space, ElemType& s) {
//	InitSpace(space);
//	int S = Malloc(space);
//	int r = S;
//	int n, m;
//	cin >> m >> n;
//	for (int j = 1; j <= m; j++) {
//		int i = Malloc(space);
//		cin >> space[i].data;
//		space[r].cur = i;
//		r = i;
//	}
//	space[r].cur = 0;
//	for (int j = 1; j <= n; ++j) {
//		cin >> b;
//		p = S;
//	}
//}//Difference
Status InsertElem(Component& Space, SLinkList list, int i, ElemType e) {
	int p = list;
	int j = 0;
	while (p && j < i - 1) {
		p = Space[p].cur;
		++j;
	}
	if (!p || j > i - 1)return ERROR;
	int n = Malloc(Space);
	Space[n].data = e;
	Space[n].cur = Space[p].cur;
	Space[p].cur = n;
	return OK;
}//InsertElem
Status DeleteElem(Component& space, SLinkList list, int i, ElemType e) {
    int p = list;
    int j = 0;
    while (p && j < i - 1) {
        p = space[p].cur;
        ++j;
    }
    if (!p || j > i - 1)return ERROR;
    SLinkList n = space[p].cur;
    e = space[n].data;
    Free(space, n);
    space[p].cur = space[n].cur;
    return OK;
}//DeleteElem
int ListLength(Component& space, SLinkList list) {
    int j = 0; 
	while (list) {
        list = space[list].cur;
		++j;
	}
	return j;
}//ListLength
Status ListTraverse(Component space, SLinkList list, int(*func)(ElemType e)) {
	while (list && !func(space[list].data))
		list = space[list].cur;
	if (list)return ERROR;
	return OK;
}//ListTraverse
Status InitList(Component& space, SLinkList list){
	list=Malloc(space);
	space[list].cur=0;
	return OK;
}//InitList
bool ListEmpty(Component space, SLinkList list){
	return space[list].cur==0;
}//ListEmpty
Status GetElem(Component space, SLinkList list, int i, ElemType& e) {
    int j = 0;
    while (list&&j < i) {
        list = space[list].cur;
        ++j;
    }
    if (!list || j < i)return ERROR;
    e = space[list].data;
    return OK;
}//GetElem

