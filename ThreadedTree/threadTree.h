#pragma once
#include<stdio.h>
#include<stdlib.h>

//线索二叉树数据结构实现
typedef char elem_t;

typedef struct treeNode {
	elem_t data;
	struct treeNode* left;
	struct treeNode* right;
	int ltag;
	int rtag;
}treeNode;

typedef struct threadedTree {
	treeNode* root;
	size_t count;
}threadedTree;

threadedTree* creatTree();
void destroyTree(threadedTree* tree);
void initTree(threadedTree* tree, treeNode* root);
treeNode* createTreeNode(elem_t value);
void insertNode(threadedTree* tree, treeNode* root, treeNode* left, treeNode* right);
void visitNode(treeNode* node);
void threadTree(threadedTree* tree);
void inorderTreadedTree(threadedTree* tree);