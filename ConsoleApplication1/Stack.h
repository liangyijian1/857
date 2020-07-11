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


//初始化栈，栈底和栈顶指针指向同一个地址，于是栈为空
void InitSqStack(SqStack &s) {			
	s.top = -1;
}

//判断栈空
bool StackEmpty(SqStack s){
	if (s.top == -1)
		return true;
	else
		return false;
}

//取栈顶元素
bool GetTop(SqStack s, ElemType& e) {
	if (StackEmpty(s))
		return false;
	e = s.data[s.top];
	return true;
}

//压栈
bool push(SqStack &s, ElemType e) {
	if (s.top == STACK_INIT_SIZE - 1)
		return false;
	s.data[++s.top] = e;
	return true;
}

//出栈
bool Pop(SqStack& s, ElemType& e) {
	if (StackEmpty(s))
		return false;
	e = s.data[s.top--];
	return true;
}