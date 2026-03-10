#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int elem_t;
typedef struct Lnode {//单链表结点
	elem_t data;
	struct Lnode* next;
}Lnode;
typedef struct LinkStack {//链式栈表头
	Lnode* top;
	size_t num;
}LinkStack;

void init(LinkStack* stack);
void push(LinkStack* stack, elem_t value);
void pop(LinkStack* stack);
elem_t top(LinkStack* stack);
int empty(LinkStack* stack);
void clear(LinkStack* stack);