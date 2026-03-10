#include"heapSort.h"

void test1() {//堆排序的时间复杂度为O(nlogn) 成功！
	int n = 10000;
	Table* t = createTable(n, 0, 100);

	check(t, heapSort);;

	releaseTable(t);
}

int main() {
	test1();

	return 0;
}