#include"linkQueue.h"
/*
* 表
* 1.顺序表（表头+正文数据区）：可自动扩容，仿vector设计
* 2.链表（三种）：带头节点、带头指针、无头
* 2.栈
*	a.顺序栈（四种）：满递增栈、满递减栈、空递增栈、空递减栈
*	b.链式栈
* 3.队列
	a.顺序队列（注意循环，不要造成虚溢出、以及判定空队列和满队列的条件，队列只能存储MAXSIZE-1个元素）
	b.链式队列：注意边界条件，空/满队列的if判断
*/

void test1() {//链式队列 成功！           至此 表完结  
	LinkQueue*q = init();
	for (int i = 1; i <= 5; ++i) {
		push(q, i * 10);
	}
	for (int i = 0; i < 3; ++i) {
		printf("%d\n",front(q));
		pop(q);
	}
	releaseQueue(q);
}

int main() {

	test1();


	return 0;
}