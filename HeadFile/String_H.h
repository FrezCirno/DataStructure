#ifndef STRING_H_H
#define STRING_H_H

#include "DS.h"
typedef struct{
    char* ch;
    int length;
}HString;

Status StrAssign(HString&, char*);
Status StrCopy(HString&, HString);
Status StrEmpty(HString);
int StrCompare(HString, HString); //>=<
int StrLength(HString);
Status ClearString(HString&);
Status Concat(HString&, HString, HString);
Status SubString(HString&, HString, int pos, int len);
Status Index(HString, HString, int pos);
Status Replace(HString&, HString, HString);
Status StrInsert(HString&, int, HString);
Status StrDelete(HString&, int, HString);
Status DestroyString(HString);

#endif