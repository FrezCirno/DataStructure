#include <iostream>
using namespace std;
#include "List_Sq.h"
int main() {
	SqList list1, list2;
	InitList(list1);
	InitList(list2);

	for (int i = 1; i < 101; ++i)
		ListInsert(list1, 1, 1.0 / i);

	for (int i = 1; i < 101; ++i)
		ListInsert(list2, 1, -1.0 / i);

	Union(list1, list2);
	ListTraverse(list1, Show);
	cout << ListLength(list1) << endl;
	return 0;
}
