#pragma once
#include<stdio.h>
#include<stdlib.h>

/*邻接表 数据设计*/
//边
typedef struct Edge {
	int note;
	int weight;
	struct Edge* next;
}Edge;

//顶点
typedef struct Vertex {
	int note;
	Edge* firstout;
	char* show;
}Vertex;

//邻接表
typedef struct AGraph {
	Vertex* node;
	int direct;
	int edgeNum;
	int nodeNum;
}AGraph;

AGraph* createGraph(int n);
void initGraph(AGraph* graph, char* ch[], int size, int direct);
void releaseGraph(AGraph* graph);
void addEdge(AGraph* graph, int a, int b, int weight);
void visitNode(AGraph* graph, int note);
void DFS(AGraph* graph, int start);
void BFS(AGraph* graph, int start);