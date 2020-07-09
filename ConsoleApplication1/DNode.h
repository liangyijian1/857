#pragma once
#include<iostream>
using namespace std;
#define Elemtype int

typedef struct DNode {
	Elemtype data;
	struct DNode* prior;
	struct DNode* next;
}DNode,*DLinklist;

bool Insert_DNode(DLinklist L, int i, Elemtype e) {
	DLinklist p=L,s;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!(s = (DLinklist)malloc(sizeof(DNode))))
		return false;
	else
	{
		s->data = e;
		s->next = p->next;
		p->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}	
}

bool Dele_DNode(DLinklist L, int i,Elemtype& e) {
	DLinklist p = L, s;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	s = p->next;
	e = s->data;
	p->next = s->next;
	s->next->prior = p;
	free(s);
	return true;
}


void Create_DNode_1(DLinklist& L,int n) {
	L = (DLinklist)malloc(sizeof(DNode));
	L->next = L->prior = NULL;
	DLinklist p;
	for (int i = 0; i < n; i++) {
		p = (DLinklist)malloc(sizeof(DNode));
		cin >> p->data;
		p->next = L->next;
		if (L->next)
			L->next->prior = p;
		L->next = p;
		p->prior = L;
	}

}

void Dis_DNode(DLinklist L) {
	DLinklist p = L->next;
	while (p) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << "\n";
}