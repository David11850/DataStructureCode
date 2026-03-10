#include"arrayStack.h"

/*满递增栈*/
void init(ArrayStack* stack) {
	stack->top = -1;
}

void push(ArrayStack* stack, elem_t value) {
	if (stack->top >= MAXSIZE - 1) {
		printf("\nFull Stack!\n");
		return;
	}
	//满递增栈
	stack->data[++stack->top] = value;
	printf("%d ", value);
}

void pop(ArrayStack* stack) {
	if (stack->top <= -1) {
		printf("\nEmpty Stack!\n");
		return;
	}
	--stack->top;//出栈并不是真的删除这个地址的数据，而是使得这个地址不再受保护（可被更改）
}

elem_t top(ArrayStack* stack) {
	if (stack->top <= -1) {
		printf("\nEmpty Stack!\n");
		return -1;
	}
	return stack->data[stack->top];
}

int empty(ArrayStack* stack) {
	return stack->top == -1;
}

void clear(ArrayStack* stack) {
	stack->top = -1;
	printf("Clear Stack\n");
}


/*满递减栈*/
void initFullDeStack(ArrayStack* stack) {
	stack->top = MAXSIZE;
}

void pushFullDeStack(ArrayStack* stack, elem_t value) {
	if (stack->top <= 0) {
		printf("Full Stack\n");
		return;
	}
	--stack->top;
	stack->data[stack->top] = value;
	printf("%d ", stack->data[stack->top]);
}

void popFullDeStack(ArrayStack* stack) {
	if (stack->top >= MAXSIZE) {
		printf("\nEmpty Stack\n");
		return;
	}
	++stack->top;
}

elem_t topFullDeStack(ArrayStack* stack) {
	if (stack->top >= MAXSIZE) {
		printf("\nEmpty Stack\n");
		return;
	}
	return stack->data[stack->top];
}

int emptyFullDeStack(ArrayStack* stack) {
	return stack->top == MAXSIZE;
}

void clearFullDeStack(ArrayStack* stack) {
	stack->top = MAXSIZE;
}


/*空递增栈*/
void initEmptyUp(ArrayStack* stack) {
	stack->top = 0;
}

void pushEmptyUp(ArrayStack* stack, elem_t value) {
	if (stack->top >= MAXSIZE) {
		printf("Full Stack\n");
		return;
	}
	stack->data[stack->top] = value;
	++stack->top;
	printf("%d ", value);
}

void popEmptyUp(ArrayStack* stack) {
	if (stack->top - 2 < 0) {
		printf("Empty Stack\n");
		return;
	}
	--stack->top;
}

elem_t topEmptyUp(ArrayStack* stack) {
	if (stack->top - 2 < 0) {
		printf("Empty Stack\n");
		return;
	}
	--stack->top;
	return stack->data[stack->top];
	++stack->top;
}

int emptyEmptyUp(ArrayStack* stack) {
	return stack->top == 0;
}

void clearEmptyUp(ArrayStack* stack) {
	stack->top = 0;
}


/*空递减栈*/
void initEmptyDe(ArrayStack* stack) {
	stack->top = MAXSIZE - 1;
}

void pushEmptyDe(ArrayStack* stack, elem_t value) {
	if (stack->top < 0) {//满
		printf("Full Stack\n");
		return;
	}
	stack->data[stack->top] = value;
	--stack->top;
	printf("%d ", value);
}

void popEmptyDe(ArrayStack* stack) {
	if (stack->top >= MAXSIZE - 1) {//空
		printf("EMpty STack\n");
		return;
	}
	++stack->top;
}

elem_t topEmptyDe(ArrayStack* stack) {
	if (stack->top >= MAXSIZE - 1) {
		printf("EMpty STack\n");
		return;
	}
	return stack->data[++stack->top];
	--stack->top;
}

int emptyEmptyDe(ArrayStack* stack) {
	return stack->top == MAXSIZE - 1;
}

void clearEmptyDe(ArrayStack* stack) {
	stack->top == MAXSIZE - 1;
}