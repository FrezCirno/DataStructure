#include <iostream>
using namespace std;
#include "../HeadFile/String_S.h"
int main() {
	SString s1, s2;
	StrAssign(s1, "abcabcabc");
	StrAssign(s2, "cabc"); //0110
//    cout<<StrLength(s1)<<endl;
//    PrintString(s1);
//    PrintString(s2);
	cout << Index(s1, s2, 1);
	return 0;
}
