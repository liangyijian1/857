#pragma once
#include<iostream>
using namespace std;
#define ElemType int


typedef struct LNode {
	ElemType data;
	struct LNode* Next;
}LNode,*Linklist;

void Dis_L(Linklist L) {
	Linklist s = (Linklist)malloc(sizeof(LNode));
	s = L->Next;
	while (s) {
		cout << s->data<<"\t";
		s = s->Next;
	}
	cout << "\n";
}

void CreatList_L_1(Linklist& L, int n) {
	L = (Linklist)malloc(sizeof(LNode));
	L->Next = NULL;
	Linklist s;
	for (int i = 0; i < n; i++) {
		s = (Linklist)malloc(sizeof(LNode));
		cin >> s->data;
		s->Next = L->Next;
		L->Next = s;
	}
}

void CreatList_L_2(Linklist& L, int n) {
	L = (Linklist)malloc(sizeof(LNode));
	L->Next = NULL;
	Linklist r, t=L;
	for (int i = 0; i < n; i++) {
		r = (Linklist)malloc(sizeof(LNode));
		cin >> r->data;
		t->Next = r;
		t = r;
	}
	t->Next = NULL;
}

Linklist GetElem(Linklist L, int i) {				//取出单链表中第i个节点
	int j = 1;
	Linklist p = L->Next;
	if (i == 0)
		return L;
	if (i < 1)
		return NULL;
	while (p && j < i) {
		p = p->Next;
		j++;
	}
	return p;
	
}

void Insert_LNode(Linklist L, int i, int x) {
	Linklist p, q;
	p = L->Next;
	int j = 1;
	while (p != NULL && j < i-1) {
		p = p->Next;
		j++;
	}
	if (p == NULL)
		cout << "不存在" << endl;
	else {
		q = (Linklist)malloc(sizeof(LNode));
		q->data = x;
		q->Next = p->Next;
		p->Next = q;
	}
}