#pragma once
#include<stdio.h>
#include<stdlib.h>

/*双向循环链表 数据结构实现*/
typedef int elem_t;
typedef struct Lnode {
	struct Lnode* prev;
	elem_t data;
	struct Lnode* next;
}Lnode;

typedef struct DLtable {
	Lnode header;
	int num;
}DLtable;

/*函数接口*/
void init(DLtable* table);
void push_front(DLtable* table, elem_t value);
void push_back(DLtable* table, elem_t value);
void pop_front(DLtable* table);
void pop_back(DLtable* table);
void delValue(DLtable* table, elem_t value);
void destroyList(DLtable* table);
void showList(DLtable* table);