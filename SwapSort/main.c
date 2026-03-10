#include"swapSort.h"

void test1() {//交换排序 完成！（轻松）    冒泡排序（3种）、快速排序（两种 双边查找+单边查找pivot）;
	int n = 10000;
	Table* t = createTable(n, 0, 100);
	Table* t1 = copyTable(t);
	Table* t2 = copyTable(t);
	Table* t3 = copyTable(t);
	Table* t4 = copyTable(t);

	check(t, bubbleSortV1);
	check(t1, bubbleSortV2);
	check(t2, bubbleSortV3);
	check(t3, quickSortV1);
	check(t4, quickSortV2);

	releaseTable(t);
	releaseTable(t1);
	releaseTable(t2);
	releaseTable(t3);
	releaseTable(t4);
}

int main() {
	test1();


	return 0;
}