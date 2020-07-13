#pragma once
#include<iostream>
using namespace std;
#define ElemType int

int cnt=0;

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

//��ֵת��
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
