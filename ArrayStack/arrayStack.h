#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

/*顺序栈的数据结构实现（满递增栈）*/
typedef int elem_t;
typedef struct ArrayStack {
	elem_t data[MAXSIZE];
	int top;
}ArrayStack;

void init(ArrayStack* stack);
void push(ArrayStack* stack, elem_t value);
void pop(ArrayStack* stack);
elem_t top(ArrayStack* stack);
int empty(ArrayStack* stack);
void clear(ArrayStack* stack);

/*顺序栈的数据结构实现（满递减栈）-类编译器的栈结构实现*/
void initFullDeStack(ArrayStack* stack);
void pushFullDeStack(ArrayStack* stack, elem_t value);
void popFullDeStack(ArrayStack* stack);
elem_t topFullDeStack(ArrayStack* stack);
int emptyFullDeStack(ArrayStack* stack);
void clearFullDeStack(ArrayStack* stack);

/*空递增栈*/
void initEmptyUp(ArrayStack* stack);
void pushEmptyUp(ArrayStack* stack, elem_t value);
void popEmptyUp(ArrayStack* stack);
elem_t topEmptyUp(ArrayStack* stack);
int emptyEmptyUp(ArrayStack* stack);
void clearEmptyUp(ArrayStack* stack);

/*空递减栈*/
void initEmptyDe(ArrayStack* stack);
void pushEmptyDe(ArrayStack* stack, elem_t value);
void popEmptyDe(ArrayStack* stack);
elem_t topEmptyDe(ArrayStack* stack);
int emptyEmptyDe(ArrayStack* stack);
void clearEmptyDe(ArrayStack* stack);
