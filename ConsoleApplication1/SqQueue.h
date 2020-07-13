#pragma once
#include<iostream>
using namespace std;
#define ElemType int
#define MaxSize 50

typedef struct {
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

//初始化
void init_SqQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
}


//判断空
bool SqQueue_isEmpty(SqQueue& q) {
	if (q.rear == q.front)
		return true;
	else
		return false;
}


//入队
bool EnSqQueue(SqQueue& q, ElemType e) {
	if ((q.rear + 1) % MaxSize == q.front)
		return false;
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}

//出队
bool DeSqQueue(SqQueue& q, ElemType& x) {
	if (SqQueue_isEmpty)
		return false;
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}