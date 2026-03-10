#include"mergeSort.h"

void test1() {//归并排序 时间复杂度O(nlong) 空间复杂度T(n) 稳定排序 自排序
	int n = 10000;
	Table* t = createTable(n, 0, 100);

	check(t, mergeSort);

	releaseTable(t);
}

int main() {
	test1();

	return 0;
}