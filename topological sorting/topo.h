#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

/*拓扑排序 数据设计*/
typedef struct matrixGraph {
	int v[MAXSIZE][MAXSIZE];
	int vertexNum;
	int edgeNum;
	int directed;
}matrixGraph;

/*拓扑排序 函数设计*/

//基于入度实现
matrixGraph* createMatrixGraph(int* temp[][10], int vNum, int eNum, int directed);
void releaseMatrixGraph(matrixGraph* g);
void topoSort(matrixGraph* g);

//基于dfs的实现
void dfsTopo(matrixGraph* g);