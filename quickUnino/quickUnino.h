#pragma once
#include<stdio.h>
#include<stdlib.h>

//并查集 quickUnino(路径压缩版本)
//数据设计
typedef char elem_t;
typedef struct quickUninoSet {
	elem_t* data;
	int* parentID;
	int* size;
	int maxsize;
	int cur;
}quickUninoSet;

//用于路径压缩的栈
typedef struct stack {
	int data;
	struct stack* next;
}stack;

quickUninoSet* createSet(int size);
void releaseSet(quickUninoSet*set);
void insert(quickUninoSet* set, elem_t* value, int size);
int search(quickUninoSet* set, elem_t a, elem_t b);
void unino(quickUninoSet* set, elem_t a, elem_t b);