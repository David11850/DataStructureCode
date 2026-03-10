#include"prim.h"

MatrixGraph* createGraph(int n[][7], int size, int directed) {
	MatrixGraph* graph = malloc(sizeof(MatrixGraph));
	graph->vertexNum = size;
	graph->edgeNum = 0;
	graph->directed = directed;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			graph->g[i][j] = n[i][j];
			if (n[i][j] != INF) {
				++graph->edgeNum;
			}
		}
	}
	return graph;
}

void releaseGraph(MatrixGraph* graph) {
	if (graph == NULL) {
		return;
	}
	free(graph);
}

static int my_end(int* isin, int size) {
	int tag = 1;

	for (int i = 0; i < size; ++i) {
		if (isin[i] == 0) {
			tag = 0;
			break;
		}
	}

	return tag;
}

static void getMini(int* cost, int* isin,int size, int* index, int* num) {
	int mini = INF;
	for (int i = 0; i < size; ++i) {
		if (isin[i] == 0 && cost[i] < mini) {
			mini = cost[i];
			*index = i;
		}
	}
	*num = mini;
}

void prim(MatrixGraph* graph, int start) {
	int* cost = malloc(sizeof(int) * graph->vertexNum);
	for (int i = 0; i < graph->vertexNum; ++i) {
		cost[i] = INF;
	}
	int* isin = malloc(sizeof(int) * graph->vertexNum);
	for (int i = 0; i < graph->vertexNum; ++i) {
		isin[i] = 0;
	}
	int* from = malloc(sizeof(int) * graph->vertexNum);
	for (int i = 0; i < graph->vertexNum; ++i) {
		from[i] = -1;
	}

	cost[start] = 0;
	isin[start] = 1;
	from[start] = start;

	for (int i = 0; i < graph->vertexNum; ++i) {
		if (graph->g[start][i] < cost[i]) {
			cost[i] = graph->g[start][i];
			from[i] = start;
		}
	}
	int index = 0, num = 0, wholeweight = 0;

	while (!my_end(isin, graph->vertexNum)) {
		getMini(cost, isin, graph->vertexNum, &index, &num);
		if (num == INF) {
			break;
		}
		isin[index] = 1;
		wholeweight += num;
		for (int i = 0; i < graph->vertexNum; ++i) {
			if (isin[i]==0 && graph->g[index][i] < cost[i] && graph->g[index][i]!=0) {
				cost[i] = graph->g[index][i];
				from[i] = index;
			}
		}
	}

	printf("wholeWeight:%d\n", wholeweight);
	for (int i = 0; i < graph->vertexNum; ++i) {
		printf("%d--%d:%d\n", i, from[i], cost[i]);
	}
}