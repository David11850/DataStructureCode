#include"find.h"

void test1() {//[查找] 遍历 二分 哈希 成功！
	int size = 100000, po = 99973;
	Data* data = createData(size);

	//普通遍历查找-时间复杂度 O(n)
	checkOrdinary(data, size);

	//二分查找-时间复杂度 O(logn)
	checkBinaryV1(data, size);
	checkBinaryV2(data, size);

	//哈希查找-时间复杂度 O(C)
	HashData** table = createHashTable(data, size, po);
	checkHash(data, size, table,po);
	releaseHashTable(table, size);

	releaseData(data);
}



int main() {
	test1();

	return 0;
}