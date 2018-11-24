#define MAXBOOKNUM  1000
#define MAXKEYNUM   2500
#define MAXLINELEN  500
#define MAXWORDNUM  10
typedef int ElemType;
#include"../HeadFile/String_H.h"
#include"../HeadFile/List_Link.h"
typedef struct {
	char** item;
	int last;
} WordListType;
typedef struct {
	HString keyword;
	LinkList bnolist;
} IdxTermType;
typedef struct {
	IdxTermType item[MAXKEYNUM + 1];//use 0
	int last;
} IdxListType;
/*                      _________________________
IdxListType -> item -> |_0|_1|_2|_3|_____________
		  \_.->last ->-./
*/
char* buf;
WordListType wdlist;

void InitIdxList(IdxListType& idxlist);
void GetLine(FILE* f);
void ExactKeyWord(ElemType& bno);
Status InsIdxList(IdxListType& idxlist, ElemType bno);
void Save(FILE* g, IdxListType idxlist);

void GetWord(int i, HString& wd);
int Locate(IdxListType idxlist, HString wd, bool& exist);
Status InsertNewKey(IdxListType& idxlist, int i, int bno);
Status InsertBook(IdxListType& idxlist, int bno);
