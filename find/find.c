#include"find.h"

Data* createData(int size) {
	Data* d = (Data*)malloc(sizeof(Data) * size);
	for (int i = 0; i < size; ++i) {
		d[i].key = i;
		d[i].d = NULL;
	}
	return d;
}

void releaseData(Data* d) {
	if (d) {
		free(d);
	}
}

//查找算法 最普通的时间复杂度为 O(n)
int ordinarySearch(Data* d, int size, Data target) {
	for (int i = 0; i < size; ++i) {
		if (d[i].key == target.key) {
			return i;
		}
	}
	return -1;
}

//二分查找
//闭区间
int binarySearchV1(Data* d, int size, Data target) {
	int left = 0, right = size - 1, mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (d[mid].key == target.key) {
			return mid;
		}
		else if (d[mid].key < target.key) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

//开区间
int binarySearchV2(Data* d, int size, Data target) {
	int left = 0, right = size, mid;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (d[mid].key == target.key) {
			return mid;
		}
		else if (d[mid].key < target.key) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return -1;
}

//建哈希表
HashData** createHashTable(Data* d, int size, int po) {
	HashData** table = (HashData*)malloc(sizeof(HashData*) * size);
	for (int i = 0; i < size; ++i) {
		table[i] = NULL;
	}

	for (int i = 0; i < size; ++i) {
		int tag = d[i].key % po;
		HashData* data = (HashData*)malloc(sizeof(HashData));
		data->value = d[i];
		data->next = table[tag];
		table[tag] = data;
	}
	return table;
}

//释放哈希表
void releaseHashTable(HashData** table, int size) {
	for (int i = 0; i < size; ++i) {
		while (table[i]) {
			HashData* temp = table[i];
			table[i] = table[i]->next;
			free(temp);
			temp = NULL;
		}
	}
	free(table);
}

//哈希查找 链式存储（类似邻接表）
int hashSearch(Data* d, int size,HashData**table, Data target, int po) {
	int tag = target.key % po;
	HashData* temp = table[tag];
	while (temp) {
		if (temp->value.key == target.key) {//成功
			return target.key;
		}
		else {
			temp = temp->next;
		}
	}
	return -1;
}








void checkOrdinary(Data* d, int size) {
	clock_t start = clock();
	for (int i = 0; i < size; ++i) {
		if (ordinarySearch(d, size, d[i]) != i) {
			printf("Wrong\n");
			return;
		}
	}
	clock_t end = clock();
	printf("Time: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void checkBinaryV1(Data* d, int size) {
	clock_t start = clock();
	for (int i = 0; i < size; ++i) {
		if (binarySearchV1(d, size, d[i]) != i) {
			printf("Wrong\n");
			return;
		}
	}
	clock_t end = clock();
	printf("Time: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void checkBinaryV2(Data* d, int size) {
	clock_t start = clock();
	for (int i = 0; i < size; ++i) {
		if (binarySearchV2(d, size, d[i]) != i) {
			printf("Wrong\n");
			return;
		}
	}
	clock_t end = clock();
	printf("Time: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void checkHash(Data* d, int size, HashData** table, int po) {
	clock_t start = clock();
	for (int i = 0; i < size; ++i) {
		if (hashSearch(d, size, table, d[i], po) != d[i].key) {
			printf("Wrong\n");
			return;
		}
	}
	clock_t end = clock();
	printf("Time: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);
}