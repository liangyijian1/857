#pragma once
#include<iostream>
using namespace std;
#define ElemType int

int cnt=0;

typedef struct LinkStack {
	ElemType data;
	struct LinkStack* next;
}*LiStack;


//初始化
void Init_LiStack(LiStack& top) {
	top = NULL;
}

//栈空
bool StackEmpty2(LiStack top) {
	if (!top)
		return true;
	else
		return false;
}

//进栈,不带头结点的单链表，top指向栈顶
bool push2(LiStack& top, ElemType e) {
	LiStack p;
	p = (LiStack)malloc(sizeof(LinkStack));
	if (!p)
		return false;
	p->data = e;
	p->next = NULL;
	if (!top) 
		top = p;
	else {
		p->next = top;
		top = p;
	}
	return true;
}

//弹栈
bool Pop2(LiStack& top, ElemType& e) {
	if (StackEmpty2(top))
		return false;
	LiStack p=top;
	top = top->next;
	e = p->data;
	free(p);
}

//输出
void Dis_LinkStack(LiStack top) {
	LiStack p = top;
	while (p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << "\n";
}

//数值转换
void convertion(int n, int d) {
	LiStack L;
	int k, e;
	Init_LiStack(L);
	while (n>0)
	{
		k = n % d;
		push2(L, k);
		n = n / d;
	}
	while (L)
	{
		Pop2(L, e);
		cout << e ;
	}
}

//汉诺塔递归
void move(int id, char from, char to) {
	cnt++;
	cout << cnt << ":" << from << "\tto\t" << to << endl;
}

void hanoi(int n, char x, char y, char z) {
	if (n == 1)
		move(1, x, z);
	else
	{
		hanoi(n - 1, x, z, y);
		move(n, x, z);
		hanoi(n - 1, y, x, z);
	}
}
