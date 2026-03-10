#include"quickUnino.h"

quickUninoSet* createSet(int size) {
	quickUninoSet* set = (quickUninoSet*)malloc(sizeof(quickUninoSet));
	if (!set) return;
	set->data = (elem_t*)malloc(sizeof(elem_t) * size);
	set->parentID = (int*)malloc(sizeof(int) * size);
	set->size = (int*)malloc(sizeof(int) * size);
	set->maxsize = size;
	set->cur = 0;
	return set;
}

void releaseSet(quickUninoSet* set) {
	if (set) {
		free(set->data);
		free(set->parentID);
		free(set->size);
		free(set);
	}
}

void insert(quickUninoSet* set, elem_t* value, int size) {
	if (set->cur + size <= set->maxsize) {
		for (int i = 0; i < size; ++i) {
			set->data[i] = value[i];
			set->parentID[i] = i;
			set->size[i] = 1;
		}
		set->cur += size;
	}
}

static int findIndex(const quickUninoSet* set, elem_t value) {
	for (int i = 0; i < set->cur; ++i) {
		if (set->data[i] == value)
			return i;
	}
	return -1;
}

static int findRoot(const quickUninoSet* set, int index) {
	if (index == -1)
		return -1;
	if (set) {
		while (index != set->parentID[index]) {
			index = set->parentID[index];
		}
		return index;
	}
}

static int findRootByPathCompress(const quickUninoSet* set, int index) {
	if (index == -1)
		return -1;
	stack* top = NULL;
	while (index != set->parentID[index]) {
		stack* node = (stack*)malloc(sizeof(stack));
		node->data = index;
		node->next = top;
		top = node;
		index = set->parentID[index];
	}

	//Â·¾¶Ñ¹Ëõ
	while (top) {
		stack* temp = top;
		set->parentID[temp->data] = index;
		top = temp->next;
		free(temp);
	}

	return index;
}

int search(const quickUninoSet* set, elem_t a, elem_t b) {
	int indexa = findIndex(set, a);
	int indexb = findIndex(set, b);

	int roota = findRoot(set, indexa);
	int rootb = findRoot(set, indexb);

	if (roota == -1 || rootb == -1)
		return 0;

	return roota == rootb;
}

void unino(quickUninoSet* set, elem_t a, elem_t b) {
	int indexa = findIndex(set, a);
	int indexb = findIndex(set, b);

	int roota = findRootByPathCompress(set, indexa);
	int rootb = findRootByPathCompress(set, indexb);

	if ((roota == -1 || rootb == -1) || (roota == rootb))
		return;

	if (set->size[roota] < set->size[rootb]) {
		set->parentID[roota] = set->parentID[rootb];
		set->size[rootb] += set->size[roota];
	}
	else {
		set->parentID[rootb] = set->parentID[roota];
		set->size[roota] += set->size[rootb];
	}
}