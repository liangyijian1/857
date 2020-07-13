#pragma once
#include<iostream>
using namespace std;
#define ElemType int
#define MaxSize 50

typedef struct {
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

//��ʼ��
void init_SqQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
}


//�жϿ�
bool SqQueue_isEmpty(SqQueue& q) {
	if (q.rear == q.front)
		return true;
	else
		return false;
}


//���
bool EnSqQueue(SqQueue& q, ElemType e) {
	if ((q.rear + 1) % MaxSize == q.front)
		return false;
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}

//����
bool DeSqQueue(SqQueue& q, ElemType& x) {
	if (SqQueue_isEmpty)
		return false;
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}