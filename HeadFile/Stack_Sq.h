#ifndef STACK_SQ_H
#define STACK_SQ_H

#include "DS.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;
/*	 __________________________________________________
base|_1|_2|_3|_top|__|__|______________________________|
*/
Status InitStack(SqStack &);
Status DestoryStack(SqStack &);
Status ClearStack(SqStack &);
bool StackEmpty(SqStack);
int StackLength(SqStack);
Status GetTop(SqStack, ElemType &);
Status Push(SqStack &, ElemType);
Status Pop(SqStack &, ElemType &);
Status StackTraverse(SqStack, int (*)(ElemType)); //from base to top
#endif