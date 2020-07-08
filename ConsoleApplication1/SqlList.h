#pragma once
#include<iostream>
using namespace std;

#define ElemType int
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct
{
    ElemType* data;
    int length, maxsize;
}SqList;


void CreateList(SqList& L)
{
    L.data = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (!L.data)
        exit(1);
    L.length = 0;
    L.maxsize = LIST_INIT_SIZE;
}

bool DeleList(SqList& L, int num, ElemType& e) {
    if (num<1 || num>L.length || L.length == 0)
        return false;
    e = L.data[num - 1];
    for (int j = num; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return false;
}

void DispList(SqList L)
{
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << "\t";
    cout << "\n";
}

void ElemIn(SqList& L, ElemType* a, int n) {
    if (!a)exit(0);
    for (int i = 0; i < n; i++)
    {
        L.data[i] = a[i];
    }
    L.length = n;
}

int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

bool Del_Min(SqList& L, ElemType& value) {
    if (L.length == 0)
        return false;
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}


void Reverse(SqList& L) {
    ElemType tmp;
    for (int i = 0; i < L.length / 2; i++) {
        tmp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = tmp;
    }
}

void Del_All_x(SqList& L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

bool Del_s_t(SqList& L, ElemType s, ElemType t) {   //前提是有序表
    int i, j;
    if (s >= t || L.length == 0)
        return false;
    for (i = 0; L.data[i] < s && i < L.length; i++) {};
    for (j = i; L.data[j] < t && j < L.length; j++) {};
    for (; j < L.length; i++, j++)
        L.data[i] = L.data[j];
    L.length = i;
    return true;
}

bool Del_s_t_2(SqList& L, ElemType s, ElemType t) {        //不是有序表，s<t
    int i, k = 0;
    if (s >= t || L.length == 0)
        return false;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] >= s && L.data[i] <= t)
            k++;
        else
            L.data[i - k] = L.data[i];
    }
    L.length -= k;
    return true;

}

bool Merge(SqList A, SqList B, SqList& C) {
    if (A.length + B.length > C.maxsize)
        return false;
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length)
        C.data[k++] = A.data[i++];
    while (j < B.length)
        C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}

bool Del_Some(SqList& L) {
    if (L.length == 0)
        return false;
    int i = 0, j = 1;
    for (; j < L.length; j++) {
        if (L.data[i] != L.data[j])
            L.data[++i] = L.data[j];
    }
    L.length = i + 1;
    return true;
}
