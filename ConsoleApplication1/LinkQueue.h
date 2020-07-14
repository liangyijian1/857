#pragma once
#include<iostream>
using namespace std;
#define ElemType int

//���н��
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode* next;
};
//��ͷ����βָ��
typedef struct LinkQueue {
	LinkNode* front, * rear;
};

//��ʼ��
void Init_LinkQueue(LinkQueue& q) {
	q.front = q.rear = (LinkNode*)malloc(sizeof(LinkNode));//����ͷ���
	q.front->next = NULL;//��ʼΪ��
}

//�п�
bool LinkQueue_isEmpty(LinkQueue q) {
	if (q.front == q.rear)
		return true;
	else
		return false;
}

//���
void EnLinkQueue(LinkQueue& q, ElemType e) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = NULL;
	q.rear->next = s;
	q.rear = s;
}

//����
bool DeLinkQuquq(LinkQueue& q, ElemType &e) {
	if (LinkQueue_isEmpty)			//�п�
		return false;
	LinkNode* p = q.front->next;
	e = p->data;
	q.front->next = p->next;
	if (q.rear==p)
	{
		q.rear = q.front;			//��ԭ������ֻ��һ����㣬ɾ������
	}
	free(p);
	return true;
}