#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define INF 100000000 

typedef struct MatrixGraph {
	int g[MAXSIZE][MAXSIZE];
	int vertexNum;
	int edgeNum;
	int directed;
}MatrixGraph;

MatrixGraph* createGraph(int n[][7], int size, int directed);
void releaseGraph(MatrixGraph* graph);

void prim(MatrixGraph* graph, int start);