#include"quickFind.h"

quickFindSet* createSet(int size) {
	quickFindSet* set = (quickFindSet*)malloc(sizeof(quickFindSet));
	set->data = (elem_t*)malloc(sizeof(elem_t) * size);
	set->groupID = (int*)malloc(sizeof(int) * size);
	set->maxsize = size;
	set->cur = 0;
	return set;
}

void releaseSet(quickFindSet* set) {
	if (set) {
		free(set->data);
		free(set->groupID);
		free(set);
	}
}

void insert(quickFindSet* set, const elem_t* value, int n) {
	if (set->cur + n <= set->maxsize) {
		for (int i = 0; i < n; ++i) {
			set->data[i] = value[i];
			set->groupID[i] = i;
		}
		set->cur += n;
	}
}

static int find(quickFindSet* set, elem_t value) {
	for (int i = 0; i < set->cur; ++i) {
		if (set->data[i] == value)
			return i;
	}
	return -1;
}

int search(quickFindSet* set, elem_t a, elem_t b) {
	int indexa = -1, indexb = -1;
	indexa = find(set, a);
	indexb = find(set, b);
	if (indexa == -1 || indexb == -1)
		return 0;
	return set->groupID[indexa] == set->groupID[indexb];
}

void unino(quickFindSet* set, elem_t a, elem_t b) {
	int indexa = -1, indexb = -1;
	indexa = find(set, a);
	indexb = find(set, b);
	if ((indexa == -1 || indexb == -1) || (set->groupID[indexa] == set->groupID[indexb]))
		return;
	for (int i = 0; i < set->cur; ++i) {
		if (set->groupID[i] == set->groupID[indexa]) {
			set->groupID[i] = set->groupID[indexb];
		}
	}
}