#include"matrixGraph.h"

void initGraph(matrixGraph* graph, char* ch[], int num, int direct, int weight) {
	if (graph == NULL || num > MAXSIZE) {
		return;
	}
	for (int i = 0; i < num; ++i) {
		graph->vertex[i].note = i;
		graph->vertex[i].show = ch[i];
	}
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			graph->edge[i][j] = weight;
		}
	}
	graph->direct = direct;
	graph->edgeNum = 0;
	graph->num = num;
}

void addEdge(matrixGraph* graph, int a, int b,int weight) {
	if (a < 0 || a >= graph->num || b < 0 || b >= graph->num) {
		return;
	}
	graph->edge[a][b] = weight;
	if (graph->direct == 0) {//无向
		graph->edge[b][a] = weight;
	}
	++graph->edgeNum;
}

void showVertex(matrixGraph*graph,int n) {
	printf("%s\t", graph->vertex[n].show);
}

void dfs(matrixGraph* graph, int start) {
	static int visit[MAXSIZE];
	memset(visit, 0, sizeof(visit));
	
	//满递增栈
	int my_stack[MAXSIZE];
	int index = -1;

	++index;
	my_stack[index] = start;
	visit[start] = 1;

	int cur;

	while (index != -1) {
		cur = my_stack[index];
		--index;
		if (index < -1) {
			printf("invalid stack\n");
		}
		showVertex(graph, cur);		
		
		for (int i = graph->num-1; i >= 0; --i) {
			if (graph->edge[cur][i] == 1 && visit[i] == 0) {
				++index;
				my_stack[index] = i;
				visit[i] = 1;
			}
		}
	}
}

void bfs(matrixGraph* graph, int start) {
	static int visit[MAXSIZE];
	memset(visit, 0, sizeof(visit));

	//循环队列
	int my_queue[MAXSIZE];
	int head = 0, tail = 0;

	my_queue[tail] = start;
	tail = (tail + 1) % MAXSIZE;
	visit[start] = 1;

	int cur;

	while (tail != head) {
		cur = my_queue[head];
		head = (head + 1) % MAXSIZE;
		showVertex(graph, cur);

		for (int i = 0; i < graph->num; ++i) {
			if (graph->edge[cur][i] == 1 && visit[i] == 0) {
				my_queue[tail] = i;
				tail = (tail + 1) % MAXSIZE;
				visit[i] = 1;
			}
		}
	}
}