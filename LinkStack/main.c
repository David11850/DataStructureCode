#include"linkStack.h"

void test1() {//链式栈 成功！
	LinkStack* st = malloc(sizeof(LinkStack));//分配在堆段上
	init(st);
	for (int i = 0; i < 10; ++i) {
		push(st, i + 10);
	}

	for (int i = 0; i < 6; ++i) {
		pop(st);
	}
	clear(st);
	printf("IsEmpty:%d", empty(st));
	pop(st);//测试是否会下溢
	free(st);
}

int main() {
	test1();

	return 0;
}