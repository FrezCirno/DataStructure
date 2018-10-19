#include <iostream>
using namespace std;
#include "List_Link.h"
int main() {
	LinkList list1 = NULL;
	ElemType e;
	InitList(list1);

	for (int i = 0; i < 100; ++i) {
		ListInsert(list1, 1, 1.0 / i);
	}

	ListDelete(list1, 1, e);
	ListTraverse(list1, Show);
	return 0;
}