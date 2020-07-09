#include<iostream>
#include<stdlib.h>
#include"Linklist.h"
#include"SqlList.h"
#include"DNode.h"

using namespace std;

int main() {
    DLinklist L;
    int num;
    Create_DNode_1(L, 5);
    Dis_DNode(L);
    Insert_DNode(L, 3, 99);
    Dis_DNode(L);
    Dele_DNode(L, 4, num);
    Dis_DNode(L);
}