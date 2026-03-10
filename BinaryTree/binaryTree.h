#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 8

typedef char elem_t;
typedef struct TreeNode {
	elem_t data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
typedef struct BinaryTree {
	TreeNode* root;
	size_t num;
}BinaryTree;

BinaryTree* creatTree();
void destroyTree(BinaryTree* tree);
TreeNode* createNode(elem_t value);
BinaryTree* insert(BinaryTree* tree, TreeNode* parent, TreeNode* left, TreeNode* right);
void show(TreeNode* node);
void levelOrderTree(BinaryTree* tree);
void preOrderTree(BinaryTree* tree);
void inOrderTree(BinaryTree* tree);
void postOrderTree(BinaryTree* tree);