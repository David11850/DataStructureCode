#include"swapSort.h"

//交换函数
static void my_swap(Value* a, Value* b) {
	Value temp;
	memcpy(&temp, a, sizeof(Value));
	memcpy(a, b, sizeof(Value));
	memcpy(b, &temp, sizeof(Value));
}

//冒泡排序V1
void bubbleSortV1(Table* t) {
	//n个元素  需要循环n-1次/轮
	for (int i = 0; i < t->length - 1; ++i) {
		//每一轮找到一个最大值 第二轮就减少一次比较 故每轮比较n-1-i次
		for (int j = 0; j < t->length - 1 - i; ++j) {
			if (t->v[j].key > t->v[j + 1].key) {
				my_swap(&t->v[j], &t->v[j + 1]);
			}
		}
	}
}

//由于交换排序 冒泡排序会将小的数值推向左侧 大的数值推向右侧 因此可能在某轮交换结束以后 已经有序 但是仍然循环n-1次
//因此可以做些优化 当某轮完全没有执行交换的时候 便确定已经有序 停止后序的比较
void bubbleSortV2(Table* t) {
	//冒泡排序 执行n-1轮
	for (int i = 0; i < t->length - 1; ++i) {
		//每轮找到一个最大值 减少一次比较
		int tag = 0;
		for (int j = 0; j < t->length - 1 - i; ++j) {
			if (t->v[j].key > t->v[j + 1].key) {
				my_swap(&t->v[j], &t->v[j + 1]);
				tag = 1;
			}
		}
		if (tag == 0) {
			break;
		}
	}
}

//冒泡排序V3
//其实还可以进行更加细致的优化 我们让交换排序 循环只停留在最后一次交换位置下标之前
void bubbleSortV3(Table* t) {
	int mark, n = t->length - 1;
	do {
		mark = 0;//初始化mark位置
		for (int i = 0; i < n; ++i) {
			if (t->v[i].key > t->v[i + 1].key) {
				my_swap(&t->v[i], &t->v[i + 1]);
				mark = i;//更新最后一次交换的下标位置mark
			}
		}
		n = mark + 1;//使得循环停留在mark之前
	} while (mark > 0);
}






//--------------------------------------------------------------------
//双边寻找法
//先动右边right 找到比基准小的元素下标位置
//再动左边left 找到比基准打的元素下标位置
//交换两个越界者 交换left与pivot（默认为start下标）
//直到left==right 说明找到pivot的位置了
static int findPivotDouble(Table* t, int start, int end) {
	int pivot = start;
	int left = start;
	int right = end;

	while (left != right) {//left与right相遇 退出循环 找到pivot
		//先动右边--保证最后一次交换不会由问题
		while (right > left && t->v[right].key > t->v[pivot].key) {
			--right;
		}
		//再动左边--必须带等号 不然会交换默认pivot的值 导致快排失败
		while (left < right && t->v[left].key <= t->v[pivot].key) {
			++left;
		}
		//退出循环说明找到了异端/默认pivot就是pivot
		if (left < right) {
			my_swap(&t->v[left], &t->v[right]);
		}
	}
	//退出循环说明找到pivot的位置了
	my_swap(&t->v[pivot], &t->v[left]);

	//返回pivot位置
	return left;
}

//单边查找法
// mark默认为start下标
//利用唯一的一个mark作为挡板 左边的比mark值小、右边的比mark值大
static int findPivotSingle(Table* t, int start, int end) {
	int mark = start;//挡板 标记小于基准值的最后一个数值的下标 默认是start
	elem_t val = t->v[start].key;//保存默认的基准值 用于数值大小比较，若遇到小于基准值的 则++mark
	//遍历元素 比mark小 则与mark+1位置进行交换（+1是为了保证最后的交换没有问题）
	for (int i = start + 1; i <= end; ++i) {
		if (t->v[i].key < val) {
			my_swap(&t->v[mark + 1], &t->v[i]);//若i==1，则原地交换 无妨 || 若i!=1，则mark+1必定大于mark，交换也无妨
			++mark;//挡板后移 小于基准值的区域+1
		}
	}
	//退出循环说明 挡板位置就是最后一个小于基准值的下标位置 与pivot交换 即可让pivot位于应待的位置 并且左侧都是小于基准值的数值 右侧都是大于的数值
	my_swap(&t->v[mark], &t->v[start]);
	return mark;
}

//递归调用快排 使用双边查找法 寻找中轴值
static void MyquickSortV1(Table* t, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = findPivotDouble(t, start, end);
	MyquickSortV1(t, start, pivot - 1);
	MyquickSortV1(t, pivot + 1, end);
}

//递归调用快排 使用单边查找法 寻找中轴值
static void MyquickSortV2(Table* t, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = findPivotSingle(t, start, end);
	MyquickSortV2(t, start, pivot - 1);
	MyquickSortV2(t, pivot + 1, end);
}

//快速排序 O(nlogn);
//核心是找到中轴心点pivot，确定它的排序位置 再递归左右边界
void quickSortV1(Table* t) {
	MyquickSortV1(t, 0, t->length - 1);
}

void quickSortV2(Table* t) {
	MyquickSortV2(t, 0, t->length - 1);
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

Table* copyTable(Table* t) {
	Table* temp = (Table*)malloc(sizeof(Table));
	temp->v = (Value*)malloc(sizeof(Value) * t->length);
	temp->length = t->length;
	for (int i = 0; i < t->length; ++i) {
		temp->v[i] = t->v[i];
	}
	return temp;
}