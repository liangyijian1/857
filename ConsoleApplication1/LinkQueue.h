#pragma once
#include<iostream>
using namespace std;
#define ElemType int

//队列结点
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode* next;
};
//队头、队尾指针
typedef struct LinkQueue {
	LinkNode* front, * rear;
};

//初始化
void Init_LinkQueue(LinkQueue& q) {
	q.front = q.rear = (LinkNode*)malloc(sizeof(LinkNode));//建立头结点
	q.front->next = NULL;//初始为空
}

//判空
bool LinkQueue_isEmpty(LinkQueue q) {
	if (q.front == q.rear)
		return true;
	else
		return false;
}

//入队
void EnLinkQueue(LinkQueue& q, ElemType e) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = NULL;
	q.rear->next = s;
	q.rear = s;
}

//出队
bool DeLinkQuquq(LinkQueue& q, ElemType &e) {
	if (LinkQueue_isEmpty)			//判空
		return false;
	LinkNode* p = q.front->next;
	e = p->data;
	q.front->next = p->next;
	if (q.rear==p)
	{
		q.rear = q.front;			//若原队列中只有一个结点，删除后变空
	}
	free(p);
	return true;
}