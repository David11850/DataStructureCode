#include"linkQueue.h"

LinkQueue* init() {
	LinkQueue* q = malloc(sizeof(LinkQueue));
	q->front = q->rear = NULL;
	q->num = 0;
}

void push(LinkQueue* queue, elem_t value) {
	LNode* node = malloc(sizeof(LNode));
	node->data = value;
	node->next = NULL;
	if (queue->rear == NULL) {//空链式队列
		queue->rear = node;
		queue->front = node;
	}
	else {
		queue->rear->next = node;
		queue->rear = node;
	}
	++queue->num;
}

void pop(LinkQueue* queue) {
	if (queue->front == NULL) {
		printf("Empty queue\n");
		return;
	}
	LNode* temp = queue->front;
	queue->front = queue->front->next;
	free(temp);
	--queue->num;
}

elem_t front(LinkQueue* queue) {
	if (queue->front == NULL) {
		printf("Empty queue\n");
		return;
	}
	return queue->front->data;
}

void releaseQueue(LinkQueue* queue) {
	LNode* p = queue->front;//局部变量，栈段
	while (p) {//释放数据区
		LNode* temp = p;
		p = p->next;
		free(temp);
		--queue->num;
	}
	printf("Release num:%d\n", queue->num);
	queue->front = queue->rear = NULL;
	free(queue);//释放表头
}