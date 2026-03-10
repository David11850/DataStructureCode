#include"linkStack.h"

void init(LinkStack* stack) {
	stack->top = NULL;
	stack->num = 0;
}

void push(LinkStack* stack, elem_t value) {
	Lnode* node = malloc(sizeof(Lnode));
	node->data = value;
	node->next = stack->top;
	stack->top = node;
	stack->num++;
	printf("%d ", stack->top->data);
}

void pop(LinkStack* stack) {
	if (stack->num <= 0) {
		printf("\nEmpty Stack\n");
		return;
	}
	Lnode* temp = stack->top;//备份思想
	stack->top = stack->top->next;
	free(temp);
	stack->num--;
}

elem_t top(LinkStack* stack) {
	if (stack->num <= 0) {
		printf("\nEmpty Stack\n");
		return;
	}
	return stack->top->data;
}

int empty(LinkStack* stack) {
	return stack->num == 0;
}

void clear(LinkStack* stack) {
	while (stack->num > 0) {
		Lnode* temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
		--stack->num;
	}
	printf("\nNum:%d\n", stack->num);
}