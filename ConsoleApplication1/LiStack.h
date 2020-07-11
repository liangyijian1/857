#pragma once
#include<iostream>
using namespace std;
#define ElemType int

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