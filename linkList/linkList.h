#pragma once
#include<stdio.h>
#include<stdlib.h>

/*带头结点的单链表 数据结构实现*/
typedef int elem_t;
typedef struct Lnode {  //链表结点
	elem_t data;
	struct Lnode* next;
}Lnode;

typedef struct LinkTable {  //头节点
	Lnode* header;  //结点
	int num;  //元素个数
}LinkTable;

/*单链表 接口函数*/
void insertHead(LinkTable* table, elem_t value);			//头插
void insertTail(LinkTable* table, elem_t value);			//尾插
void insertPos(LinkTable* table, int pos, elem_t value);	//在指定下标位置插入

void showList(LinkTable* table);							//打印链表
void deleteList(LinkTable* table);							//删除链表


/*带头指针的单链表 数据结构实现*/
typedef struct LinkList {
	Lnode* ptr_Lnode;
	int num;
}LinkList;

void insertHeadList(LinkList* list, elem_t value);
void insertTailList(LinkList* list, elem_t value);
void insertPosList(LinkList* list, int pos, elem_t value);
void showLinkList(LinkList* list);
void deleteValueLinkList(LinkList* list, elem_t value);
void deleteLinkList(LinkList* list);

/*无头单链表 函数接口*/
Lnode* insertHeadNoHead(Lnode* ptr, elem_t value);
Lnode* insertTailNoHead(Lnode* ptr, elem_t value);
Lnode* insertPosNoHead(Lnode* ptr, int pos, elem_t value);
void showNoHead(Lnode* ptr);
Lnode* deleteValueNoHead(Lnode* ptr, elem_t value);
void deleteNoHead(Lnode* ptr);