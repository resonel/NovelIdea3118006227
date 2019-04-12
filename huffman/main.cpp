#include <iostream>
#include "huff.h"
#include <string>
using namespace std;
int main()
{
	cout<<"ÇëÊäÈë±àÂëÄÚÈÝ£º"<<endl;
	char cod[100];
	cin>>cod;
	htTree *codeTree=buildTree(cod);
	hlTable *codeTable=buildTable(codeTree);
	encode(codeTable,cod);
	return 0;
	decode(codeTree,"001111110011");
}