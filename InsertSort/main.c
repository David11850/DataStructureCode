#include"insertSort.h"

void test1() {//插入排序 成功！（直接插入排序-有序去和无序区    希尔排序（间隔gap））
	int n = 10000;
	Table* t = createTable(n, 0, 100);
	check(t, directInsertSort);
	check(t, shellSort);
	releaseTable(t);
}

int main() {
	test1();


	return 0;
}