#include"adjacenceGraph.h"

void test() {//成功！！
	AGraph* graph = createGraph(5);
	char* names[] = { "A", "B", "C", "D", "E" };
	initGraph(graph, names, sizeof(names) / sizeof(names[0]), 1);

	addEdge(graph, 0, 4, 1);
	addEdge(graph, 0, 3, 1);
	addEdge(graph, 0, 1, 1);
	addEdge(graph, 1, 4, 1);
	addEdge(graph, 1, 2, 1);
	addEdge(graph, 2, 0, 1);
	addEdge(graph, 3, 2, 1);

	printf("图的边数: %d\n", graph->edgeNum);
	printf("图的深度遍历：");
	DFS(graph, 0);

	printf("\n图的广度遍历：");
	BFS(graph, 0);
}


int main() {
	test();
	return 0;
}