#pragma once
#include<stdio.h>
#include<stdlib.h>

/*数据设计*/
typedef struct Edge {
	int to;
	int weight;
	struct Edge* next;
}Edge;

typedef struct Vertex {
	int data;
	struct Edge* firstEdge;
}Vertex;

typedef struct Graph {
	Vertex* v;
	int vertexNum;
	int edgeNum;
}Graph;

Graph* createdGraph(int* num, int size);
void releaseGraph(Graph* g);
void addEdge(Graph* g, int start, int end, int weight);

/*关键路径
	ve
	vl
	ee
	el
*/

void createKeyPath(Graph* g);