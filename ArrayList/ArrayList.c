#include"ArrayList.h"

void initArrayList(ArrayList* table, int num) {		//已有表头，初始化正文数据区
	table->data = malloc(sizeof(elem_t) * num);
	table->capacity = num;
	table->len = 0;
}

void deleteArrayList(ArrayList* table) {
	free(table->data);
	table->data = NULL;
	table->capacity = 0;
	table->len = 0;
}

ArrayList* creatArrayList(int num) {		//初始化表头和正文数据区
	ArrayList* temp = malloc(sizeof(ArrayList));
	temp->data = malloc(sizeof(elem_t) * num);
	temp->capacity = num;
	temp->len = 0;
	return temp;
}

void releaseArrayList(ArrayList* table) {
	free(table->data);
	free(table);
}

static int enlarger(ArrayList* table) {		//扩容函数，仅在该文件呢使用，故创建为在data数据段上的静态函数
	// 1. 申请一块原空间的2倍大小
	elem_t* temp = malloc(sizeof(elem_t) * (2 * table->capacity));
	if (temp == NULL) {
		printf("Enlarge failed!\n");
		return 1;
	}
	// 2. 把原空间的内容拷贝到新空间，原空间[0,capacity)范围拷贝新空间的[0, capacity)范围
	for (int i = 0; i < table->capacity; ++i) {
		temp[i] = table->data[i];
	}
	// 3. 释放原空间，更新表头
	free(table->data);
	table->data = temp;
	table->capacity *= 2;
	printf("Enlarge successfully!\n");
	return 0;
}

void push_backArrayList(ArrayList* table, elem_t value) {
	// 判断是否溢出，如果溢出，要扩容
	if (table->len >= table->capacity && enlarger(table)) {		//边界检查
		return;
	}
	table->data[table->len] = value;		//len就是尾插的下标索引
	++table->len;							//尾插后记得++len，更新尾插下标和正文数据区内元素的个数
}

void insertArrayList(ArrayList* table, size_t pos, elem_t value) {
	// 1. 判断输入参数有效性
	if (pos<0 || pos>table->len)	//插入位置检查
		return;
	// 2. 判断是否需要扩容
	if (table->len >= table->capacity && enlarger(table)) {		//边界检查
		return;
	}
	// 3. 把原来的[pos, len-1]的元素搬移到[pos + 1, len]这个位置，i表示要搬移的数据，搬移到i+1的位置上
	for (int i = table->len; i > pos; --i) {
		table->data[i] = table->data[i - 1];
	}
	// 4. 放入新元素
	table->data[pos] = value;
	++table->len;		//插入后记得++len，更新尾插下标和正文数据区内元素的个数
}

void showArrayList(const ArrayList* table) {
	for (int i = 0; i < table->len; ++i)
		printf("%d\t", table->data[i]);
	printf("\n");
}

void deleteValueArrayList(ArrayList* table, elem_t value) {
	for (int i = 0; i < table->len; ++i) {
		if (table->data[i] == value) {
			// 将[pos+1,len)区间的数据搬移到[pos, len - 1)区间里
			for (int j = i; j < table->len; ++j) {		//删除后，后续元素前移一个元素
				table->data[j] = table->data[j + 1];
			}
			--table->len;								//删除后记得更新len
		}
	}
}

void deletePosArrayList(ArrayList* table, size_t pos) {
	for (int i = pos; i < table->len; ++i) {
		table->data[i] = table->data[i + 1];
	}
	--table->len;
}

size_t findArrayList(ArrayList* table, elem_t value) {
	for (int i = 0; i < table->len; ++i) {
		if (table->data[i] == value) {
			return i;
		}
	}
	printf("No such value in the ArrayList!\n");
	return -1;
}