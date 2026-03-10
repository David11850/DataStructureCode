#include"heapSort.h"

Heap* createHeap(int size) {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	if (h == NULL) {
		return NULL;
	}
	h->data = (int*)malloc(sizeof(Value) * (size + 1));// 下标从1-n存储 分配n+1个空间
	if (h->data == NULL) {
		free(h);
		return NULL;
	}
	h->len = 0;
	h->capacity = size;
	return h;
}

void releaseHeap(Heap* h) {
	if (h) {
		free(h->data);
		free(h);
	}
}

//实现大顶堆
//往堆中插入元素 —— 上浮
//概念：堆本身就是一个完全二叉树 因此采用数组的形式存储 使用[i/2 i 2i 2i+1]的下标进行[父 自 左子 右子]的访问
//插入新元素的时候 要保持堆的结构（完全二叉树）：使用len往后进行增加
//要保持堆的性质（大顶堆）：保证父节点的key永远大于子节点的key 插入新元素以后 不断与自己的父节点key值作比较 如果父节点小于子节点 那么上浮
void insertHeapValue(Heap* h, Value v) {
	if (h->len + 1 > h->capacity) {
		return;
	}

	//加入堆
	int index = h->len + 1;
	int parent = index / 2;
	h->data[index] = v;

	//尝试上浮
	while (parent >= 1 && h->data[parent].key < h->data[index].key) {//大顶堆
		Value temp = h->data[parent];
		h->data[parent] = h->data[index];
		h->data[index] = temp;
		index = parent;			//更新自己下标的位置
		parent = index / 2;		//更新父节点位置
	}
	++h->len;
}

//获取堆顶元素并删除
Value getHeapValue(Heap* h) {
	//获取对顶的数值
	Value ans = h->data[1];

	//删除/转移矛盾 堆顶元素
	h->data[1] = h->data[h->len];
	--h->len;
	int index = 1;
	int chIndex = 2 * index;	//假设交换的下标是左孩子

	//尝试下沉
	while (chIndex <= h->len) {//左孩子存在
		if (chIndex + 1 <= h->len && h->data[chIndex + 1].key > h->data[chIndex].key) {//右孩子存在 并且数值大于左孩子（大顶堆）
			++chIndex;//更新交换下标
		}
		if (h->data[chIndex].key > h->data[index].key) {//子节点大于父节点（此处是大顶堆） 交换
			Value temp = h->data[chIndex];
			h->data[chIndex] = h->data[index];
			h->data[index] = temp;
			index = chIndex;
			chIndex = index * 2;//假设交换的下标是左孩子
		}
		else break;//否则退出
	}

	return ans;
}

void heapSort(Table* t) {
	Heap* h = createHeap(t->length + 10);
	for (int i = 0; i < t->length; ++i) {
		insertHeapValue(h, t->v[i]);
	}
	for (int i = 0; i < t->length; ++i) {
		t->v[i] = getHeapValue(h);
	}
	releaseHeap(h);
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