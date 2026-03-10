#include"matrixGraph.h"

void test() {//³É¹¦£¡
	matrixGraph graph;
	char* nodeNames[] = {
		"V1", "V2", "V3", "V4",
		"V5", "V6", "V7", "V8"
	};
	initGraph(&graph, nodeNames, 8, 0, 0);
	addEdge(&graph, 0, 1, 1);
	addEdge(&graph, 0, 2, 1);
	addEdge(&graph, 1, 3, 1);
	addEdge(&graph, 1, 4, 1);
	addEdge(&graph, 2, 5, 1);
	addEdge(&graph, 2, 6, 1);
	addEdge(&graph, 3, 7, 1);
	addEdge(&graph, 4, 7, 1);
	addEdge(&graph, 5, 6, 1);

	printf("edge num = %d\n", graph.edgeNum);
	printf("DFS: ");
	dfs(&graph, 0);

	printf("\nBFS: ");
	bfs(&graph, 0);

}


int main() {
	test();
	return 0;
}