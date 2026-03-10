#include"kruskal.h"

//并查集-quickunino函数实现
Set* setCreate(int n) {
	Set* set = malloc(sizeof(Set));
	if (set == NULL) {
		return;
	}
	set->parent = malloc(sizeof(int) * n);
	if (set->parent == NULL) {
		return;
	}
	for (int i = 0; i < n; ++i) {
		set->parent[i] = i;// 初始化每个节点的父节点为自己
	}
	set->size = n;
	return set;
}

void setRelease(Set* set) {
	free(set->parent);
	set->size = 0;
	free(set);
}

int setFind(const Set* set, int n) {
	if (n<0 || n>set->size || set == NULL) {
		return -1;
	}
	while (set->parent[n] != n) {
		n = set->parent[n];
	}
	return n;// 返回根节点
}

void setUnino(Set* set, int n, int m) {
	if (n<0 || n>set->size || m<0 || m>set->size) {
		return;
	}
	int np = setFind(set, n);
	int mp = setFind(set, m);
	if (np == mp) {
		return;
	}
	set->parent[np] = mp;
}

//边集数组函数实现
Edge* edgeCreate(const Matrix* m) {
	if (m == NULL) {
		return;
	}
	Edge* edge = malloc(sizeof(Edge));
	edge->size = 0;
	edge->start = malloc(sizeof(int) * m->edgeNum);
	edge->end = malloc(sizeof(int) * m->edgeNum);
	edge->weight = malloc(sizeof(int) * m->edgeNum);
	for (int i = 0; i < m->nodeNum; ++i) {
		for (int j = i; j < m->nodeNum; ++j) {
			if (m->matrix[i][j] != 0) {
				edge->start[edge->size] = i;
				edge->end[edge->size] = j;
				edge->weight[edge->size] = m->matrix[i][j];
				++edge->size;
			}
		}
	}
	return edge;
}

void edgeRelease(Edge* edge) {
	if (edge == NULL) {
		return;
	}
	free(edge->start);
	free(edge->end);
	free(edge->weight);
	free(edge);
}

static void my_swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

Edge* edgeSort(Edge* edge) {
	for (int i = 0; i < edge->size-1; ++i) {
		for (int j = i+1; j < edge->size; ++j) {
			if (edge->weight[i] > edge->weight[j]) {
				my_swap(&edge->start[i], &edge->start[j]);
				my_swap(&edge->end[i], &edge->end[j]);
				my_swap(&edge->weight[i], &edge->weight[j]);
			}
		}
	}
	return edge;
}

Edge* kruskal(Edge* edge, int n) {
	if (edge == NULL) {
		return;
	}

	Edge* result = malloc(sizeof(Edge));
	result->start = malloc(sizeof(int) * n);
	result->end = malloc(sizeof(int) * n);
	result->weight = malloc(sizeof(int) * n);
	result->size = 0;
	Set* set = setCreate(n);

	for (int i = 0; i < edge->size; ++i) {
		if (result->size >= n) {
			break;
		}
		int na = setFind(set, edge->start[i]);
		int nb = setFind(set, edge->end[i]);
		if (na != nb) {
			result->start[result->size] = edge->start[i];
			result->end[result->size] = edge->end[i];
			++result->size;
			setUnino(set, na, nb);
		}
	}
	setRelease(set);
	return result;
}