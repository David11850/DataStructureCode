#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int elem_t;
typedef struct Value {
	elem_t key;
	void* data;
}Value;

typedef struct Table {
	Value* v;
	int length;
}Table;

typedef void(*sortFun)(Table* t);
void bubbleSortV1(Table* t);
void bubbleSortV2(Table* t);
void bubbleSortV3(Table* t);
void quickSortV1(Table* t);
void quickSortV2(Table* t);
Table* createTable(int num, int low, int high);
void releaseTable(Table* t);
int check(Table* t, sortFun s);
Table* copyTable(Table* t);