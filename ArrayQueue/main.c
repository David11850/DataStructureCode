#include"arrayQueue.h"

void test1() {//顺序队列 成功
	ArrayQueue q;
	init(&q);
	for (int i = 1; i < 5; ++i) {
		push(&q, i * 10);
	}
	push(&q, 999);//队满提示，队列实际容量为MAXSIZE-1，因为要实现判空和判满的区别
	for (int i = 0; i < 3; ++i) {
		printf("Delete front:%d\n", front(&q));
		pop(&q);
	}
	pop(&q);
}


int main() {
	test1();


	return 0;
}