#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef enum { RED, BLACK } Color;
typedef int RBKey;

typedef struct RBNode {
	Color color;
	RBKey key;
	struct RBNode* left;
	struct RBNode* right;
	struct RBNode* parent;
}RBNode;

typedef struct RBTree {
	RBNode* root;
	int size;
}RBTree;

RBTree* createTree();
void releaseTree(RBTree* tree);
void insertNode(RBTree* tree, RBKey key);
void deleteNode(RBTree* tree, RBKey key);
void showTree(RBTree* tree);