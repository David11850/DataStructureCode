#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
/*邻接矩阵 数据设计*/
//单个顶点
typedef struct Vertex {
	int note;
	char* show;
}Vertex;

typedef struct matrixGraph {
	Vertex vertex[MAXSIZE];			//顶点
	int edge[MAXSIZE][MAXSIZE];		//边
	int num;
	int direct;
	int edgeNum;
}matrixGraph;

void initGraph(matrixGraph* graph, char* ch[], int num, int direct, int weight);
void addEdge(matrixGraph* graph, int a, int b, int weight);
void showVertex(matrixGraph* graph, int n);
void dfs(matrixGraph* graph, int start);
void bfs(matrixGraph* graph, int start);
