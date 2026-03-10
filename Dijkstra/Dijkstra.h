#pragma once
#include<stdio.h>
#include<stdlib.h>
#define INF 100000000
#define MAXSIZE 10

/*数据设计*/
typedef struct matrixGraph {
	int g[MAXSIZE][MAXSIZE];
	int vertexNum;
	int edgeNum;
	int directed;
}matrixGraph;

matrixGraph* createGraph(matrixGraph* graph, int vertexNum, int edgeNum, int directed);
void releaseGraph(matrixGraph* graph);
void Dijkstra(matrixGraph* graph, int start);
