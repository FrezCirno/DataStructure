#include <iostream>
using namespace std; 
#include "../HeadFile/String_S.h"
int main() {
	SString s1,s2;
	StrAssign(s1,"abcabcabc");
	StrAssign(s2,"cabc");
    cout<<StrLength(s1)<<endl;
    cout<<Index(s1,s2,1)<<endl;
	return 0;
}
