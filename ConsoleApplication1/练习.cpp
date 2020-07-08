#include<iostream>
#include<stdlib.h>
#include"Linklist.h"
#include"SqlList.h"

using namespace std;

int main() {
    Linklist L;
    CreatList_L_2(L,4);
    Dis_L(L);
    Insert_LNode(L, 1, 100);
    Dis_L(L);
    Del_List(L, 1);
    Dis_L(L);
}