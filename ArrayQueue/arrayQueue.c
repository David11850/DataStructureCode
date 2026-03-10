#include"arrayQueue.h"

void init(ArrayQueue* queue) {
	queue->front = queue->rear = 0;
}

void push(ArrayQueue* queue, elem_t value) {
	if ((queue->rear + 1)%MAXSIZE == queue->front) {//判断是否队满
		printf("Full queue\n");
		return;
	}
	queue->data[queue->rear] = value;
	queue->rear = (queue->rear + 1) % MAXSIZE;//循环队列
}

void pop(ArrayQueue* queue) {
	if (queue->front == queue->rear) {//判断是否队空
		printf("Empty queue\n");
		return;
	}
	queue->front = (queue->front + 1) % MAXSIZE;//loop
}

elem_t front(ArrayQueue* queue) {
	if (queue->front == queue->rear) {
		printf("Empty queue\n");
		return;
	}
	return queue->data[queue->front];
}