#include"crossList.h"

void test() {//成功！！十字链表
	CrossList* graph = createGraph(4);
	char* nodeName[] = { "V0", "V1", "V2", "V3" };
	initGraph(graph, nodeName, 4);
	addEdge(graph, 0, 3, 1);
	addEdge(graph, 1, 0, 1);
	addEdge(graph, 1, 2, 1);
	addEdge(graph, 2, 0, 1);
	addEdge(graph, 2, 1, 1);

	printf("V3的入度：%d\n", inDegree(graph, 3));
	printf("V3的出度：%d\n", outDegree(graph, 3));

	releaseGraph(graph);
}


int main() {
	test();
	return 0;
}