#include<iostream>
#include"DS.h"
using namespace std;

#define MAXSIZE 1000
typedef struct {
    ElemType data;
    int  cur;
}Component, SLinkList[MAXSIZE];

//space[0]作为备用链表的头指针，
//S作为链表的头指针；



int LocateElem(SLinkList S, ElemType e,bool (*compare)(ElemType,ElemType)) {
    int i = S[0].cur;
    while (i&&S[i].cur != 0)
        if (compare(S[i].data, e))  return i;
    return 0;
}
Status InitSpace(SLinkList& space) {
    for (int i = 0; i < MAXSIZE - 1; ++i)space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;
    return OK;
}//InitSpace
int Malloc(SLinkList& space) {
    int i = space[0].cur;
    if (i) space[0].cur = space[i].cur;
    return i;
}//Malloc
void Free(SLinkList& space, int k) {
    space[k].cur = space[0].cur; space[0].cur = k;
}//Free
/*void difference(SLinkList& space, ElemType& s) {
    InitSpace(space);
    int S = Malloc(space);
    int r = S;
    int n, m;
    cin >> m >> n;
    for (int j = 1; j <= m; j++) {
        int i = Malloc(space);
        cin >> space[i].data;
        space[r].cur = i; r = i;
    }
    space[r].cur = 0;
    for (int j = 1; j <= n; ++j) {
        cin >> b; p = S;
    }
}*/
Status InsertElem(SLinkList& Space, int list, int i, ElemType e) {
    int p = list;
    int j = 0;
    while (p&&j < i - 1) { p = Space[p].cur; ++j; }
    if (!p||j > i - 1)return ERROR;
    int n = Malloc(Space);
    Space[n].data = e;
    Space[n].cur = Space[p].cur;
    Space[p].cur = n;
    return OK;
}//InsertElem
int ListLength(SLinkList S) {
    int j = 0, i = S[1].cur;
    while (i) { i = S[i].cur; ++j; }
    return j;
}//ListLength
int disp(ElemType e) {
    cout << e << endl;
    return 0;
}
Status ListTraverse(SLinkList Space, int list, int(*func)(ElemType e)) {
    while (list && !func(Space[list].data))
        list = Space[list].cur;
    if (list)return ERROR;
    return OK;
}







int main() {
    SLinkList S;
    InitSpace(S);
    int list = 0;
    for (int i = 0; i < 100; ++i) {
        InsertElem(S, list, 1, i);
    }
    cout << "st" << endl;
    ListTraverse(S, list, disp);
    cout << "ed" << endl;
    system("pause");
    return 0;
}
