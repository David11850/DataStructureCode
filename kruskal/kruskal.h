#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
/*数据设计*/
//邻接矩阵
typedef struct Matrix{
	int matrix[MAXSIZE][MAXSIZE];
	int nodeNum;
	int edgeNum;
}Matrix;

//边集数组
typedef struct Edge {
	int* start;
	int* end;
	int* weight;
	int size;
}Edge;

//并查集-quickunino
typedef struct Set{
	int* parent;
	int size;
}Set;

//前置函数
Set* setCreate(int n);
void setRelease(Set* set);
int setFind(const Set* set, int n);
void setUnino(Set* set, int n, int m);

Edge* edgeCreate(const Matrix* m);
void edgeRelease(Edge* edge);
Edge* edgeSort(Edge* edge);

Edge* kruskal(Edge* edge, int n);