#include<iostream>
#include"DS.h"
using namespace std;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;//LinkList = head node


int main()
{
    return 0;
}

Status ListInsert(LinkList& L, int i, ElemType e) {
    LNode* p = L;
    int j = 0;
    while (p && j < i - 1) {p = p->next; ++j; }
    if (!p || j > i - 1)return ERROR;
    LNode* s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}//ListInsert
Status ListDelete(LinkList& L, int i, ElemType& e) {
    LinkList p = L; int j = 0;
    while (p->next && j < i - 1) { p = p->next; ++j; }//j=i-1
    if (!(p->next) || j > i - 1) return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}//ListDelete
Status GetElem(LinkList L, int i, ElemType& e) {
    LinkList p = L; int j = 0;
    while (p && j < i) {
        p = p->next; ++j;
    }
    if (!p || j > i)return ERROR;
    e = p->data;
    return OK;
}//GetElem
Status CreateList/*Head Insert*/(LinkList& L, int n) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LinkList p;
    for (int i = n; i > 0; --i) {
        p = (LinkList)malloc(sizeof(LNode));
        cin >> p->data;
        p->next = L->next; L->next = p;
    }
    return OK;
}//CreateList


