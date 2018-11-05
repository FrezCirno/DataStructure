#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
int Index(char* S, char* T) {
	int i, j, len1 = strlen(S), len2 = strlen(T);
	if(len1 < len2) return 0;
	int *next = (int*)malloc(len2 * sizeof(int));
	next[0] = -1;
	i = 0; j = -1;
	while (i < len2)
		if (j == -1 || T[i] == T[j]) { 
			++i; ++j;
			if (T[i] != T[j])	next[i] = j;
			else				next[i] = next[j];
		} else j = next[j];
	i = j = 0;
	while (i < len1 && j < len2)
		if (j == -1 || S[i] == T[j]) {++i; ++j;}
		else j = next[j];
	free(next);
	if (j >= len2) return i - len2;
	else return -1;
}
int main() {
	char s1[100] = "aaaaaaaaaaaaaaaaaaab", s2[100] = "ab";
	int result = Index(s1,s2);
	printf("Find result = %d\nThis char is %c", result, s1[result]);
	return 0;
}
