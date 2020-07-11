#pragma once
#include<iostream>
using namespace std;
#define ElemType int

typedef struct LinkStack {
	ElemType data;
	struct LinkStack* next;
}*LiStack;


//��ʼ��
void Init_LiStack(LiStack& top) {
	top = NULL;
}

//ջ��
bool StackEmpty2(LiStack top) {
	if (!top)
		return true;
	else
		return false;
}

//��ջ,����ͷ���ĵ�����topָ��ջ��
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

//��ջ
bool Pop2(LiStack& top, ElemType& e) {
	if (StackEmpty2(top))
		return false;
	LiStack p=top;
	top = top->next;
	e = p->data;
	free(p);
}

//���
void Dis_LinkStack(LiStack top) {
	LiStack p = top;
	while (p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << "\n";
}