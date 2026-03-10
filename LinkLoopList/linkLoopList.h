#pragma once
#include<stdio.h>
#include<stdlib.h>

/*单项循环链表 数据设计*/
typedef int elem_t;
typedef struct Lnode {
	elem_t data;
	struct Lnode* next;
}Lnode;

//带头节点的表头
typedef struct LinkTable {
	Lnode header;
	int num;
	Lnode* rear;
}LinkTable;

/*函数接口*/
void initLinkLoopList(LinkTable* table);
void InsertHeadLinkLoopTable(LinkTable* table, elem_t v);
void insertTailLinkLoopTable(LinkTable* table, elem_t v);

void showLinkLoopTable(LinkTable* table);
void deleteValueLinkLoopTable(LinkTable* table, elem_t v);
void destroyLinkLoopTable(LinkTable* table);