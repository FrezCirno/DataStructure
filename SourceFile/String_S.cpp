#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#include "../HeadFile/String_S.h"
Status StrAssign(SString& S, char* src){
	int len=strlen(src);
	if(len>MAXSTRLEN) S[0]=MAXSTRLEN;
	else S[0]=len;
	unsigned char* dst = S + 1;
	for(int i=0;i<S[0];++i) dst[i]=src[i];
	if(len>MAXSTRLEN)return OVERFLOW;
	return OK;
}//StrAssign
Status StrCopy(SString&, SString);
bool StrEmpty(SString S) {
	return S[0] == 0;
} //StrEmpty
int StrCompare(SString, SString); //>=<
int StrLength(SString S) {
	return S[0];
} //StrLength
Status ClearString(SString& S) {
	for (int i = S[0]; i >= 0; --i)
		S[i] = 0;
	return OK;
} //ClearString
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
int Index(SString S, SString T, int pos) {
	if(S[0] < T[0]+pos-1) return FALSE;
	int *next=(int*)malloc((T[0] + 1) * sizeof(int));
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T[0])
		if (j == 0 || T[i] == T[j]) { 
			++i; ++j;
			if (T[i] != T[j]) next[i] = j;
			else next[i] = next[j];
		} else j = next[j];
	j = 1;
	while (pos <= S[0] && j <= T[0]) 
		if (j == 0 || S[pos] == T[j]) {++pos; ++j;} 
		else {j = next[j];}
	free(next);
	if (j > T[0]) return pos - T[0];
	else return FALSE;
} //Index
Status Replace(SString&, SString, SString);
Status StrInsert(SString&, int, SString);
Status StrDelete(SString&, int, SString);
Status DestroyString(SString);
Status PrintString(SString S){
	for(int i=1;i<=S[0];++i)cout<<S[i];
}//PrintString
