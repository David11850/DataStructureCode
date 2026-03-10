#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef char elem_t;
typedef struct quickFindSet {
	elem_t* data;
	int* groupID;
	int maxsize;
	int cur;
}quickFindSet;

quickFindSet* createSet(int size);
void releaseSet(quickFindSet* set);
void insert(quickFindSet* set, const elem_t* value,int n);
int search(quickFindSet* set, elem_t a, elem_t b);
void unino(quickFindSet* set, elem_t a, elem_t b);