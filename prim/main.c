#include"prim.h"

void test() {//完成prim算法还原！艰难
	int n[7][7] = {
		{0,12,INF,INF,INF,16,14},
		{12,0,10,INF,7,INF,INF},
		{INF,INF,0,3,5,6,INF},
		{INF,INF,3,0,4,INF,INF},
		{INF,INF,5,4,0,2,INF},
		{16,7,6,INF,2,0,8},
		{14,INF,INF,INF,8,9,0}
	};
	MatrixGraph* graph = createGraph(n, 7, 0);
	prim(graph, 0);


	releaseGraph(graph);
}

int main() {
	test();
	return 0;
}