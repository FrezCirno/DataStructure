#ifndef STRING_H_H
#define STRING_H_H

#include "DS.h"
typedef struct {
	char* ch;
	int length;
} HString;
/*     _______________________________
ch ->  |_|_|_|_|_|_|_|_|______________
length >= 0
*/
Status StrAssign(HString& dst, char* src);
Status StrCopy(HString& dst, HString src);
Status StrEmpty(HString str);
int StrCompare(HString str1, HString str2); //>=<
int StrLength(HString str);
Status ClearString(HString&);
Status Concat(HString&, HString, HString);
Status SubString(HString&, HString, int pos, int len);
Status Index(HString, HString, int pos);
Status Replace(HString&, HString, HString);
Status StrInsert(HString&, int, HString);
Status StrDelete(HString&, int, HString);
Status DestroyString(HString);

#endif