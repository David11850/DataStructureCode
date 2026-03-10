#include"mergeSort.h"

//合并函数 用于对给定的两个有序区间[start,mid] [mid+1,end]进行合并 得到[start,end]的有序数组 
//自排序 但是需要拷贝两份有序子区间 因此空间复杂度 n
static void my_merge(Table* t, int start, int mid, int end) {
	//因为归并排序是子排序 因此需要备份两个子空间 
	int n1 = mid - start + 1;
	int n2 = end - mid;
	if (n1 == 0 || n2 == 0) {
		return;
	}
	Value* tempa = (Value*)malloc(sizeof(Value) * n1);
	Value* tempb = (Value*)malloc(sizeof(Value) * n2);
	for (int i = 0; i < n1; ++i)tempa[i] = t->v[i];
	for (int i = 0; i < n2; ++i)tempb[i] = t->v[i];

	//开始再原数组上进行自排序
	int i = 0, j = 0, k = start;
	while (i < n1 && j < n2) {
		if (tempa[i].key <= tempb[j].key) {
			t->v[k++] = tempa[i++];
		}
		else {
			t->v[k++] = tempb[j++];
		}
	}

	//退出循环说明 有一个子数组的元素已经全部被加入了原数组 
	//接下来要对还未全部加入原数组的元素 全部按照顺序加入原数组（因为两个子数组都是有序的）
	while (i < n1) {
		t->v[k++] = tempa[i++];
	}
	while (j < n2) {
		t->v[k++] = tempb[j++];
	}

	//至此完成对于两个有序子数组的合并操作 得到[start,end]的有序数组
	free(tempa);
	free(tempb);
}

//归并排序的递归函数 对[start,end]区间进行对半划分 直到划分到一个元素 开始合并
static void my_mergeSort(Table* t, int start, int end) {
	if (start >= end) {//递归终止条件 区间只有一个元素
		return;
	}
	int mid = (start + end) / 2;
	my_mergeSort(t, start, mid);
	my_mergeSort(t, mid + 1, end);
	
	//到达这里说明划分完毕 开始合并
	my_merge(t, start, mid, end);
}

void mergeSort(Table* t) {
	my_mergeSort(t, 0, t->length - 1);
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
		if (t->v[i - 1].key < t->v[i].key) {  //大顶堆
			printf("Wrong\n");
			return 1;
		}
	}
	printf("Time:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}

Table* copyTable(Table* t) {
	Table* temp = (Table*)malloc(sizeof(Table));
	temp->v = (Value*)malloc(sizeof(Value) * t->length);
	temp->length = t->length;
	for (int i = 0; i < t->length; ++i) {
		temp->v[i] = t->v[i];
	}
	return temp;
}