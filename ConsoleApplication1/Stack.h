#pragma once
#include<iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 50
#define ElemType int

typedef struct sqstack {
	ElemType data[STACK_INIT_SIZE];
	int top;
}SqStack;


//��ʼ��ջ��ջ�׺�ջ��ָ��ָ��ͬһ����ַ������ջΪ��
void InitSqStack(SqStack &s) {			
	s.top = -1;
}

//�ж�ջ��
bool StackEmpty(SqStack s){
	if (s.top == -1)
		return true;
	else
		return false;
}

//ȡջ��Ԫ��
bool GetTop(SqStack s, ElemType& e) {
	if (StackEmpty(s))
		return false;
	e = s.data[s.top];
	return true;
}

//ѹջ
bool push(SqStack &s, ElemType e) {
	if (s.top == STACK_INIT_SIZE - 1)
		return false;
	s.data[++s.top] = e;
	return true;
}

//��ջ
bool Pop(SqStack& s, ElemType& e) {
	if (StackEmpty(s))
		return false;
	e = s.data[s.top--];
	return true;
}