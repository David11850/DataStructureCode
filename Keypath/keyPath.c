#include"keyPath.h"

Graph* createdGraph(int* num, int size) {
	Graph* g = malloc(sizeof(Graph));
	g->v = malloc(sizeof(Vertex) * size);
	g->vertexNum = size;
	for (int i = 0; i < size; ++i) {
		g->v[i].data = num[i];
		g->v[i].firstEdge = NULL;
	}
	g->edgeNum = 0;
	return g;
}

void releaseGraph(Graph* g) {
	if (g) {
		for (int i = 0; i < g->vertexNum; ++i) {
			Edge* e = g->v[i].firstEdge;
			if(e){
				Edge* temp = e;
				e = temp->next;
				free(temp);
			}
		}
		free(g->v);
		free(g);
	}
}

void addEdge(Graph* g, int start, int end, int weight) {
	Edge* e = malloc(sizeof(Edge));
	e->weight = weight;
	e->to = end;
	e->next = g->v[start].firstEdge;//头插法
	g->v[start].firstEdge = e;
	++g->edgeNum;
}

/*关键路径
	ve
	vl
	ee
	el
*/

static void calIndegree(Graph* g, int* indegree) {
	for (int k = 0; k < g->vertexNum; ++k) {
		int degree = 0;
		for (int i = 0; i < g->vertexNum; ++i) {
			for (Edge* j = g->v[i].firstEdge; j != NULL; j = j->next) {
				if(j && j->to==k)++degree;
			}
		}
		indegree[k] = degree;
	}
}

void createKeyPath(Graph* g) {
	int* indegree = malloc(sizeof(int) * g->vertexNum);
	for (int i = 0; i < g->vertexNum; ++i) {
		indegree[i] = 0;
	}
	int* queue = malloc(sizeof(int) * g->vertexNum);
	int head = 0, tail = 0;
	int* stack = malloc(sizeof(int) * g->vertexNum);
	int top = -1;

	//ve:拓扑排序 前置结点的max+自身权值 正确
	int* ve = malloc(sizeof(int) * g->vertexNum);
	for (int i = 0; i < g->vertexNum; ++i) {
		ve[i] = 0;
	}
	int index = 0;
	calIndegree(g, indegree);
	for (int i = 0; i < g->vertexNum; ++i) {
		if (indegree[i] == 0) {
			queue[tail++] = i;
		}
	}

	while (head != tail) {
		int cur = queue[head++];
		stack[++top] = cur;//为后续计算vl做准备
		for (Edge* e = g->v[cur].firstEdge; e != NULL; e = e->next) {
			--indegree[e->to];
			if (indegree[e->to] == 0) {
				queue[tail++] = e->to;
			}
			ve[e->to] = max(ve[e->to], ve[cur] + e->weight);
		}
	}

	printf("ve:\n");
	for (int i = 0; i < g->vertexNum; ++i) {
		printf("%d ", ve[i]);
	}
	printf("\n");


	//vl:拓扑排序逆序 事件最晚发生时间=前置min-自身权值 正确
	int* vl = malloc(sizeof(int) * g->vertexNum);
	for (int i = 0; i < g->vertexNum; ++i) {
		vl[i] = ve[stack[top]];
	}
	while (top != -1) {
		int cur = stack[top--];
		for (Edge* e = g->v[cur].firstEdge; e != NULL; e = e->next) {
			if (e)vl[cur] = min(vl[cur], vl[e->to] - e->weight);
		}
	}

	printf("vl:\n");
	for (int i = 0; i < g->vertexNum; ++i) {
		printf("%d ", vl[i]);
	}
	printf("\n\nKey Path:\n");

	//ee: 关键活动最早发生时间 =ve 正确
	int* ee = malloc(sizeof(int) * g->edgeNum);
	int indexE = 0;
	
	//el: 关键活动最晚发生时间 =vl-权值 正确
	int* el = malloc(sizeof(int) * g->edgeNum);
	for (int i = 0; i < g->edgeNum; ++i) {
		el[i] = 0;
	}
	for (int i = 0; i < g->vertexNum; ++i) {
		for (Edge* e = g->v[i].firstEdge; e != NULL; e = e->next) {
			if (e) {
				ee[indexE] = ve[i];
				el[indexE] = vl[e->to] - e->weight;
				if (ee[indexE] == el[indexE]) {
					printf("%d %d\n", i, e->to);
				}
				++indexE;
			}
		}
	}

	free(indegree);
	free(queue);
	free(stack);
	free(ve);
	free(vl);
	free(ee);
	free(el);
}