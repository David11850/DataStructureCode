#pragma once
#include<stdio.h>
#include<stdlib.h>

/*二叉搜索树 数据结构设计*/
typedef int elem_t;
typedef struct BSNode {
	elem_t data;
	struct BSNode* left;
	struct BSNode* right;
}BSNode;
typedef struct BSTree {
	BSNode* root;
	size_t count;
}BSTree;

/*函数接口*/
BSTree* createBinarySearchTree();
void releaseBinarySearchTree(BSTree* tree);

void insertBinarySearchTree(BSTree* tree, elem_t value);
void visitNode(BSNode* node);
void inorderBinarySearchTree(BSTree* tree);

