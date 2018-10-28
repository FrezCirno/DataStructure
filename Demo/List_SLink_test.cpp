#include <iostream>
using namespace std;
#include "List_SLink.h"
void Difference(Component& space, ElemType& s) {
	InitSpace(space);
	int S = Malloc(space);
	int r = S;
	int n, m;
	cin >> m >> n;
	for (int j = 1; j <= m; j++) {
		int i = Malloc(space);
		cin >> space[i].data;
		space[r].cur = i;
		r = i;
	}
	space[r].cur = 0;
	for (int j = 1; j <= n; ++j) {
		cin >> b;
		p = S;
	}
} //Difference
int main() {
	Component space;
	InitSpace(space);
	SLinkList list;
	InitList(space, list);
	for (int i = 0; i < 100; ++i) {
		InsertElem(space, list, 1, i);
	}
	ListTraverse(space, list, Show);
	return 0;
}
