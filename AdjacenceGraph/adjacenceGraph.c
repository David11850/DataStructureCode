#include"adjacenceGraph.h"

AGraph* createGraph(int n) {
	AGraph* graph = (AGraph*)malloc(sizeof(AGraph));
	graph->node = malloc(sizeof(Vertex) * n);
	memset(graph->node, 0, sizeof(graph->node));
	graph->edgeNum = 0;
	graph->nodeNum = 0;
	graph->direct = 0;
	return graph;
}

void initGraph(AGraph* graph, char* ch[],int size, int direct) {
	for (int i = 0; i < size; ++i) {
		graph->node[i].note = i;
		graph->node[i].show = ch[i];
		graph->node[i].firstout = NULL;
	}
	graph->nodeNum = size;
	graph->direct = direct;
}

void releaseGraph(AGraph* graph) {
	for (int i = 0; i < graph->nodeNum; ++i) {
		Edge* cur = graph[i].node->firstout, *temp;
		while (cur) {
			temp = cur;
			cur = temp->next;
			free(temp);
		}
	}
	graph->edgeNum = 0;
	graph->nodeNum = 0;
	graph->direct = 0;
	free(graph);
}

void addEdge(AGraph* graph, int a, int b, int weight) {
	Edge* newEdge = malloc(sizeof(Edge));
	newEdge->weight = weight;
	newEdge->note = b;
	//ͷ�巨
	newEdge->next = graph->node[a].firstout;
	graph->node[a].firstout = newEdge;
	++graph->edgeNum;
}

void visitNode(AGraph* graph, int note) {
	if (note<0 || note>graph->nodeNum) {
		return;
	}
	printf("%s\t", graph->node[note].show);
}

void DFS(AGraph* graph,int start) {
	int* visit = malloc(sizeof(int) * graph->nodeNum);
	for (int i = 0; i < graph->nodeNum; ++i) {
		visit[i] = 0;
	}
	int* stack = malloc(sizeof(int) * graph->nodeNum);
	int top = -1, cur;
	++top;
	stack[top] = start;

	while (top != -1) {
		cur = stack[top];
		--top;
		visitNode(graph, cur);
		visit[cur] = 1;
		Edge* curedge = graph->node[cur].firstout;
		while(curedge){
			if (visit[curedge->note] == 0) {
				++top;
				stack[top] = curedge->note;
			}
			curedge = curedge->next;
		}
	}
	free(visit);
}

void BFS(AGraph* graph, int start) {
	int* visit = malloc(sizeof(int) * graph->nodeNum);
	for (int i = 0; i < graph->nodeNum; ++i) {
		visit[i] = 0;
	}
	int* queue = malloc(sizeof(int) * graph->nodeNum);
	int front = 0, back = 0, size = graph->nodeNum, cur;
	back = (back + 1) % size;
	queue[back] = start;
	visit[start] = 1;

	while (front != back) {
		front = (front + 1) % size;
		cur = queue[front];
		visitNode(graph, cur);
		Edge* curedge = graph->node[cur].firstout;
		while (curedge) {
			if (visit[curedge->note] == 0) {
				back = (back + 1) % size;
				queue[back] = curedge->note;
				visit[curedge->note] = 1;
			}
			curedge = curedge->next;
		}
	}
	free(visit);
}