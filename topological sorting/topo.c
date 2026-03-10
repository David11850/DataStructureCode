#include"topo.h"

matrixGraph* createMatrixGraph(int temp[][10],int vNum, int eNum, int directed) {
	matrixGraph* graph = malloc(sizeof(matrixGraph));
	graph->directed = directed;
	graph->edgeNum = eNum;
	graph->vertexNum = vNum;
	for (int i = 0; i < vNum; ++i) {
		for (int j = 0; j < vNum; ++j) {
			graph->v[i][j] = temp[i][j];
		}
	}
	return graph;
}

void releaseMatrixGraph(matrixGraph* g) {
	if (g == NULL) {
		return;
	}
	free(g);
}

void topoSort(matrixGraph* g) {
	int* result = malloc(sizeof(int) * g->vertexNum);
	int* indegree = malloc(sizeof(int) * g->vertexNum);
	int* queue = malloc(sizeof(int) * g->vertexNum);
	int front = 0, end = 0, index = 0;

	for (int i = 0; i < g->vertexNum; ++i) {
		int num = 0;
		for (int j = 0; j < g->vertexNum; ++j) {
			if (g->v[j][i] == 1)++num;
		}
		indegree[i] = num;
	}

	for (int i = 0; i < g->vertexNum; ++i) {
		if (indegree[i] == 0) {
			queue[front] = i;
			front = (front + 1) % g->vertexNum;
		}
	}

	while (front != end) {
		int cur = queue[end];
		end = (end + 1) % g->vertexNum;
		result[index] = cur;
		++index;
		for (int i = 0; i < g->vertexNum; ++i) {
			if (g->v[cur][i] == 1) {
				--indegree[i];
				if (indegree[i] == 0) {
					queue[front] = i;
					front = (front + 1) % g->vertexNum;
				}
			}
		}
	}

	if (index == g->vertexNum) {
		printf("有向无环图:\n");
	}
	for (int i = 0; i < index; ++i) {
		printf("%d\t", result[i]);
	}

	free(result);
	free(indegree);
	free(queue);
}

static int dfs(matrixGraph* g, int* visit, int u, int* stack, int* index) {
	visit[u] = 1; //正在访问
	for (int i = 0; i < g->vertexNum; ++i) {
		if (g->v[u][i] == 1) {
			if (visit[i] == 1) {
				return 0; //有环
			}
			else if (visit[i] == 0) {
				if (dfs(g, visit, i, stack, index) == 0) {
					return 0; //有环
				}
			}
		}
	}

	visit[u] = 2;
	stack[*index] = u;
	++(*index);
	return 1;
}

void dfsTopo(matrixGraph* g) {
	int* visit = malloc(sizeof(int) * g->vertexNum);
	memset(visit, 0, sizeof(int) * g->vertexNum);
	int* stack = malloc(sizeof(int) * g->vertexNum);
	int index = 0;

	for(int i=0;i<g->vertexNum;++i){
		if (visit[i] == 0) {
			if (dfs(g, visit, i, stack, &index) == 0) {
				printf("Has circle\n");
				free(visit);
				free(stack);
				return 0;
			}
		}
	}

	while (index) {
		--index;
		printf("%d\t", stack[index]);	
	}
	free(visit);
	free(stack);
}