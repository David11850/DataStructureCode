#include"keyPath.h"

void test() {//关键路径 正确 收工!
	int VertexNum[] = {0,1,2,3,4,5,6,7,8 };
	Graph* g = createdGraph(VertexNum, sizeof(VertexNum) / sizeof(VertexNum[0]));
	addEdge(g, 0, 1, 6);
	addEdge(g, 0, 2, 4);
	addEdge(g, 0, 3, 5);
	addEdge(g, 1, 4, 1);
	addEdge(g, 2, 4, 1);
	addEdge(g, 3, 5, 2);
	addEdge(g, 4, 6, 9);
	addEdge(g, 4, 7, 7);
	addEdge(g, 5, 7, 4);
	addEdge(g, 6, 8, 2);
	addEdge(g, 7, 8, 4);

	createKeyPath(g);
}

int main() {
	test();
	return 0;
}