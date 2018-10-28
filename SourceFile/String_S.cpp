#include <iostream>
using namespace std;
#include "../HeadFile/String_S.h"
Status StrAssign(SString&, char*);
Status StrCopy(SString&, SString);
Status StrEmpty(SString);
int StrCompare(SString, SString); //>=<
int StrLength(SString);
Status ClearString(SString&);
Status Concat(SString& T, SString S1, SString S2) {
	int i;
	if (S1[0] + S2[0] <= MAXSTRLEN) {
		for (i = 1; i <= S1[0]; ++i)
			T[i] = S1[i];
		unsigned char* p = T + S1[0];
		for (i = 1; i < S2[0]; ++i)
			*(p + i) = S2[i];
		T[0] = S1[0] + S2[0];
		return TRUE;
	} else if (S1[0] < MAXSTRLEN) {
		for (i = 1; i <= S1[0]; ++i)
			T[i] = S1[i];
		int t = MAXSTRLEN - S1[0];
		unsigned char* p = T + S1[0];
		for (i = 1; i <= t; ++i)
			*(p + i) = S2[i];
		T[0] = MAXSTRLEN;
		return FALSE;
	} else {
		for (i = 0; i <= MAXSTRLEN; ++i)
			T[i] = S1[i];
		return FALSE;
	}
} //Concat
Status SubString(SString& sub, SString S, int pos, int len) {
	if (pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)
		return ERROR;
	for (int i = 1; i <= len; ++i)
		sub[i] = S[pos + i];
	sub[0] = len;
	return OK;
} //SubString
Status Index(SString S, SString T, int pos);
Status Replace(SString&, SString, SString);
Status StrInsert(SString&, int, SString);
Status StrDelete(SString&, int, SString);
Status DestroyString(SString);