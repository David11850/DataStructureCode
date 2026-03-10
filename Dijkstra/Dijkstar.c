#include"Dijkstra.h"

matrixGraph* createGraph(int node[][MAXSIZE], int vertexNum, int edgeNum, int directed) {
	matrixGraph* graph = malloc(sizeof(matrixGraph));
	graph->edgeNum = edgeNum;
	graph->vertexNum = vertexNum;
	graph->directed = directed;
	for (int i = 0; i < graph->vertexNum; ++i) {
		for (int j = 0; j < graph->vertexNum; ++j) {
			graph->g[i][j] = node[i][j];
		}
	}
	return graph;
}

void releaseGraph(matrixGraph* graph) {
	if (graph == NULL) {
		return;
	}
	free(graph);
}

static int findMini(int* cost, int* visited, int size) {
	int index = -1, mini = INF;

	for (int i = 0; i < size; ++i) {
		if (visited[i] == 0 && cost[i] < mini) {
			index = i;
			mini = cost[index];
		}
	}

	return index;
}

void Dijkstra(matrixGraph* graph, int start) {
	int* cost = malloc(sizeof(int)*graph->vertexNum);
	for (int i = 0; i < graph->vertexNum; ++i) {
		cost[i] = INF;
	}
	cost[start] = 0;
	int* visited = malloc(sizeof(int)*graph->vertexNum);
	for (int i = 0; i < graph->vertexNum; ++i) {
		visited[i] = 0;
	}

	for (int i = 0; i < graph->vertexNum; ++i) {
		cost[i] = graph->g[start][i];
	}

	for (int i = 0; i < graph->vertexNum; ++i) {
		int index = findMini(cost,visited, graph->vertexNum);
		if (index == -1)return;
		visited[index] = 1;

		for (int i = 0; i < graph->vertexNum; ++i) {
			if (visited[i] == 0 && graph->g[index][i] + cost[index] < cost[i]) {
				cost[i] = cost[index] + graph->g[index][i];
			}
		}
	}

	printf("Dijkstra:\n");
	for (int i = 0; i < graph->vertexNum; ++i) {
		printf("%d--%d:%d\n", start, i, cost[i]);
	}
}
