#include<iostream>
#include<stdlib.h>
#include"LiStack.h"

using namespace std;

int main() {
	int i,j=0;
	LiStack top;
	Init_LiStack(top);
	for ( i = 1; i <= 5; i++)
	{
		push2(top, i);
	}
	Dis_LinkStack(top);
	Pop2(top, j);
	cout << "\n" << j<<endl;
	Dis_LinkStack(top);
}