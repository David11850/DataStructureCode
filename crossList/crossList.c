#include"crossList.h"

CrossList* createGraph(int num) {
	CrossList* graph = malloc(sizeof(CrossList));
	if (graph == NULL) {
		return;
	}
	graph->node = malloc(sizeof(Vertex) * num);
	graph->edgeNum = 0;
	graph->vertexNum = num;
	return graph;
}

void initGraph(CrossList* graph, char* ch[], int num) {
	if (num > graph->vertexNum) {
		return;
	}
	for (int i = 0; i < num; ++i) {
		graph->node[i].note = i;
		graph->node[i].show = ch[i];
		graph->node[i].firstIn = graph->node[i].firstOut = NULL;
	}
}

void releaseGraph(CrossList* graph) {
	Edge* cur, *temp;
	for (int i = 0; i < graph->vertexNum; ++i) {
		cur = graph->node[i].firstIn;
		temp = cur;
		cur = cur->tnext;
		free(temp);
	}
	free(graph->node);
	graph->edgeNum = 0;
	graph->vertexNum = 0;
	free(graph);
}

void addEdge(CrossList* graph, int tail, int head, int weight) {
	Edge* edge = malloc(sizeof(Edge));
	if (edge == NULL) {
		return;
	}
	//头插法（避免循环找单链表的尾部）、十字链表一条边只出现一次，因此需要更新两个顶点的入边/出边数据
	edge->tail = tail;
	edge->tnext = graph->node[tail].firstOut;
	graph->node[tail].firstOut = edge;

	edge->head = head;
	edge->hnext = graph->node[head].firstIn;
	graph->node[head].firstIn = edge;

	edge->weight = weight;
}

int inDegree(CrossList* graph, int note) {
	if (note<0 || note>graph->vertexNum) {
		return;
	}
	int num = 0;
	Edge* cur = graph->node[note].firstIn;
	while (cur) {
		++num;
		cur = cur->hnext;
	}
	return num;
}

int outDegree(CrossList* graph, int note) {
	if (note<0 || note>graph->vertexNum) {
		return;
	}
	int num = 0;
	Edge* cur = graph->node[note].firstOut;
	while (cur) {
		++num;
		cur = cur->tnext;
	}
	return num;
}
