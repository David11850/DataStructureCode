#include"arrayStack.h"

void test1() {//满递增栈 成功！
	ArrayStack st;//栈段上局部变量
	init(&st);
	for (int i = 0; i < 10; ++i) {
		push(&st, i + 10);
	}
	push(&st, 999);//测试是否会有上溢

	for (int i = 0; i < 3; ++i) {
		printf("Num:%d\n", top(&st));
		pop(&st);
	}
	clear(&st);
	pop(&st);//测试是否会有下溢
}
void test2() {//满递减栈 成功！
	ArrayStack st;//栈段
	initFullDeStack(&st);
	for (int i = 0; i < 10; ++i) {
		pushFullDeStack(&st, i + 10);
	}
	pushFullDeStack(&st, 999);//test

	for (int i = 0; i < 5; ++i) {
		printf("%d ", topFullDeStack(&st));
		popFullDeStack(&st);
	}
	clearFullDeStack(&st);
	printf("IsEmpty:%d", emptyFullDeStack(&st));
	popFullDeStack(&st);//test
}
void test3() {//空递增栈 成功！
	ArrayStack st;//栈段
	initEmptyUp(&st);
	for (int i = 0; i < 10; ++i) {
		pushEmptyUp(&st, i + 10);
	}
	pushEmptyUp(&st, 999);//test

	for (int i = 0; i < 5; ++i) {
		printf("%d ", topEmptyUp(&st));
		popEmptyUp(&st);
	}
	clearEmptyUp(&st);
	printf("IsEmpty:%d\n", emptyEmptyUp(&st));
	popEmptyUp(&st);//test
}
void test4() {//空递减栈 成功！
	ArrayStack st;//栈
	initEmptyDe(&st);
	for (int i = 0; i < 10; ++i) {
		pushEmptyDe(&st, i + 10);
	}
	pushEmptyDe(&st, 999);

	for (int i = 0; i < 5; ++i) {
		printf("%d ", topEmptyDe(&st));
		popEmptyDe(&st);
	}
	clearEmptyDe(&st);
	printf("IsEmpty:%d\n", emptyEmptyDe(&st));
	popEmptyDe(&st);
}

int main() {
	//test1();
	//test2();
	//test3();
	test4();

	return 0;
}