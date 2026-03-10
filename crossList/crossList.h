#pragma once
#include<stdio.h>
#include<stdlib.h>

/*十字链表 数据设计*/
//边
typedef struct Edge {
	int tail;
	struct Edge* tnext;
	int head;
	struct Edge* hnext;
	int weight;
}Edge;

//顶点
typedef struct Vertex {
	char* show;
	int note;
	Edge* firstIn;
	Edge* firstOut;
}Vertex;

//十字链表——存储有向图
typedef struct CrossList {
	Vertex* node;
	int edgeNum;
	int vertexNum;
}CrossList;

/*函数接口*/
CrossList* createGraph(int num);
void initGraph(CrossList* graph, char* ch[], int num);
void releaseGraph(CrossList* graph);
void addEdge(CrossList* graph, int tail, int head, int weight);
int inDegree(CrossList* graph, int note);
int outDegree(CrossList* graph, int note);
