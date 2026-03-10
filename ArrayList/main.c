/*顺序表 C语言分文件实现*/
#include"ArrayList.h"

void test1() {
	//初始化表头
	ArrayList* m = malloc(sizeof(ArrayList));
	// 插入5个元素
	initArrayList(m, 5);
	for (int i = 0; i < 5; ++i) {
		push_backArrayList(m, 100 + i);
	}
	showArrayList(m);
	// 再插入一个元素
	insertArrayList(m, 2, 9999);//测试扩容
	showArrayList(m);
	deleteArrayList(m);
	free(m);
}

void test2() {
	ArrayList* list = creatArrayList(5);
	// 插入5个元素
	for (int i = 0; i < 5; ++i) {
		push_backArrayList(list, 200 + i);
	}
	showArrayList(list);
	insertArrayList(list, 3, 8888);//测试扩容
	showArrayList(list);
	deleteValueArrayList(list, 8888);
	showArrayList(list);
	for (int i = 0; i < 5; ++i) {
		push_backArrayList(list, i);
	}
	showArrayList(list);
	deletePosArrayList(list, 5);
	showArrayList(list);
	releaseArrayList(list);
}

int main() {
	test1();
	test2();

	return 0;
}