#include"insertSort.h"

//直接插入排序
void directInsertSort(Table* t) {
	//分为有序去和无序区、默认第一个元素在有序区域
	for (int i = 1; i < t->length; ++i) {
		//不断更新无序区的元素到有序区
		Value temp = t->v[i];//备份
		int j;
		for (j = i - 1; j >= 0; --j) {
			if (temp.key < t->v[j].key) {
				t->v[j + 1] = t->v[j];//移动+拷贝
			}
			else {
				break;
			}
		}	
		t->v[j + 1] = temp;
	}
}

//希尔排序
void shellSort(Table* t) {
	for (int gap = t->length / 2; gap > 0; gap/=2) {
		for (int i = gap; i < t->length; ++i) {
			Value temp = t->v[i];
			int j = i;
			while (j >= gap && t->v[j - gap].key > temp.key) {
				t->v[j] = t->v[j - gap];
				j -= gap;
			}
			t->v[j] = temp;
		}
	}
}

Table* createTable(int num, int low, int high) {
	Table* t = (Table*)malloc(sizeof(Table));
	t->v = (Value*)malloc(sizeof(Value) * num);
	t->length = num;
	srand(time(NULL) + 1);
	for (int i = 0; i < num; ++i) {
		t->v[i].key = (rand() % (high - low + 1)) + low;
		t->v[i].data = NULL;
	}
	return t;
}

void releaseTable(Table* t) {
	if (t) {
		free(t->v);
		free(t);
	}
}

int check(Table* t, sortFun s) {
	clock_t start = clock();
	s(t);
	clock_t end = clock();
	for (int i = 1; i < t->length; ++i) {
		if (t->v[i - 1].key > t->v[i].key) {
			printf("Wrong\n");
			return 1;
		}
	}
	printf("Time:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}