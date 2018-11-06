#include <iostream>
using namespace std;
#include "../HeadFile/String_H.h"
Status StrAssign(HString& T, char* chars) {
	if (T.ch)
		free(T.ch);
	int len = 0;
	char* c = chars;
	while(*c++) ++len;
	if (!len) {
		T.ch = NULL;
		T.length = 0;
	} else {
		T.ch = (char*)malloc(len * sizeof(char));
		if (!T.ch)
			exit(OVERFLOW);
		for (int i = 0; i < len; ++i)
			T.ch[i] = chars[i];
		T.length = len;
	}
	return OK;
} //StrAssign
Status StrCopy(HString&, HString);
Status StrEmpty(HString);
int StrCompare(HString str1, HString str2) {
	//>=<
    while(*str1.ch++ == *str2.ch++);
    return *--str1.ch < *--str2.ch;
} //StrCompare
int StrLength(HString S) {
	return S.length;
} //StrLength
Status ClearString(HString& S) {
	if (S.ch) {
		free(S.ch);
		S.ch = NULL;
	}
	S.length = 0;
	return OK;
} //ClearString
Status Concat(HString& T, HString S1, HString S2) {
	if (T.ch)
		free(T.ch);
	T.ch = (char*)malloc(len * sizeof(char));
	if (!T.ch)
		exit(OVERFLOW);
	for (int i = 0; i < S1.length; ++i)
		T.ch[i] = S1.ch[i];
	T.length = S1.length + S2.length;
	for (int i = 0; i < S2.length; ++i)
		T.ch[i + S1.length] = S2.ch[i];
	return OK;
} //Concat
Status SubString(HString& sub, HString S, int pos, int len) {
	if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
		return ERROR;
	if (sub.ch)
		free(sub.ch);
	if (!len) {
		sub.ch = NULL;
		sub.length = 0;
	} else {
		sub.ch = (char*)malloc(len * sizeof(char));
		for (int i = 0; i <= len; ++i)
			sub.ch[i] = S.ch[pos - 1 + i];
		sub.length = len;
	}
	return OK;
} //SubString
Status Index(HString, HString, int pos);
Status Replace(HString&, HString, HString);
Status StrInsert(HString&, int, HString);
Status StrDelete(HString&, int, HString);
Status DestroyString(HString);