#include"Dijkstra.h"

void test() {//Dijkstra最短路径算法 成功！
	int node[MAXSIZE][MAXSIZE] = {
		{0, 1, 12, INF, INF, INF},
		{INF, 0, 9, 3, INF, INF},
		{INF, INF, 0, INF, 5, INF},
		{INF, INF, 4, 0, 13, 15},
		{INF, INF, INF, INF, 0, 4},
		{INF, INF, INF, INF, INF, 0}
	};
	matrixGraph* graph = createGraph(node, 6, 9, 1);
	Dijkstra(graph, 0);
	releaseGraph(graph);
}

int main() {
	test();
	return 0;
}