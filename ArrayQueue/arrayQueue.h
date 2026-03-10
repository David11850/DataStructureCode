#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
/*顺序队列 数据结构实现*/
typedef int elem_t;
typedef struct ArrarQueue {
	elem_t data[MAXSIZE];
	size_t rear;//尾指针，用于插入
	size_t front;//头指针，用于删除
}ArrayQueue;

void init(ArrayQueue* queue);
void push(ArrayQueue* queue, elem_t value);
void pop(ArrayQueue* queue);
elem_t front(ArrayQueue* queue);
