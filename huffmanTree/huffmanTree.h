#pragma once
#include<stdio.h>
#include<stdlib.h>

//1.以顺序表的存储结构，来构建哈夫曼树这个二叉树的逻辑结构
typedef struct huffmanTreeNode {
	int weight;//权值
	int parent;//为什么要存储父亲结点的位置？用于判断此结点是都已经被构建为哈夫曼树的结点
	int lchild;
	int rchild;
}huffmanTreeNode, * huffmanTree;

//2.初始化哈夫曼树
huffmanTree* initTree(const int* ch, int n);

//3.构建哈夫曼树
huffmanTree createHuffmanTree(huffmanTree tree, int n);

void releaseTree(huffmanTree tree);

//1.构建编码表，编码表就是 字符数组 的数组
typedef char* huffmanCode;

huffmanCode* createHuffmanCode(huffmanTree tree, int n);

void releaseCode(huffmanCode* code, int n);