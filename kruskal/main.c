#include"kruskal.h"

void test() {//成功！（依旧艰难）
	Matrix m = {
		.matrix = {
			{0, 10, 6, 5, 0, 0},
			{10, 0, 0, 15, 0, 0},
			{6, 0, 0, 4, 8, 0},
			{5, 15, 4, 0, 0, 2},
			{0, 0, 8, 0, 0, 12},
			{0, 0, 0, 2, 12, 0}
		},
		.nodeNum = 6,
		.edgeNum = 8
	};

	Edge* edge = edgeCreate(&m);
	edge = edgeSort(edge);

	Edge* result = kruskal(edge, m.nodeNum);
	printf("Kruskal最小生成树结果：\n");
	for (int i = 0; i < result->size; ++i) {
		printf("边：%d - %d\n", result->start[i], result->end[i]);
	}

	edgeRelease(result);
	edgeRelease(edge);
}


int main() {
	test();
	return 0;
}