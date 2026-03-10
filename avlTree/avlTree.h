#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int elem_t;
typedef struct avlNode {
	elem_t data;
	struct avlNode* left;
	struct avlNode* right;
	size_t height;
}avlNode;

typedef struct avlTree {
	avlNode* root;
	size_t count;
}avlTree;

avlTree* createTree();
void releaseTree(avlTree*tree);
void pushNode(avlTree* tree, elem_t value);
void popNode(avlTree* tree, elem_t value);
void visit(avlTree* tree);