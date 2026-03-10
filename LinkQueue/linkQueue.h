#pragma once
#include<stdio.h>
#include<stdlib.h>

/*链式队列 数据结构实现*/
typedef int elem_t;
typedef struct LNode {
	elem_t data;
	struct Lnode* next;
}LNode;

typedef struct LinkQueue {
	LNode* front;
	LNode* rear;
	size_t num;
}LinkQueue;

LinkQueue* init();
void releaseQueue(LinkQueue* queue);
void push(LinkQueue* queue, elem_t value);
void pop(LinkQueue* queue);
elem_t front(LinkQueue* queue);
