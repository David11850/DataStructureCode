#include"binaryTree.h"

BinaryTree* creatTree() {
	BinaryTree* tree = malloc(sizeof(BinaryTree));
	tree->root = NULL;
	tree->num = 0;
	return tree;
}

static void destroyNode(BinaryTree*tree,TreeNode* node) {
	if (node == NULL)
		return;
	destroyNode(tree, node->left);
	destroyNode(tree, node->right);
	free(node);
	--tree->num;
}

void destroyTree(BinaryTree* tree) {
	if (tree) {
		destroyNode(tree, tree->root);
	}
	printf("Num:%d\n", tree->num);
	free(tree);
}

TreeNode* createNode(elem_t value) {
	TreeNode* node = malloc(sizeof(TreeNode));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BinaryTree* insert(BinaryTree* tree, TreeNode* parent, TreeNode* left, TreeNode* right) {
	if (tree == NULL || parent == NULL)
		return;
	parent->left = left;
	parent->right = right;
	if (left != NULL) ++tree->num;
	if (right != NULL) ++tree->num;
	return tree;
}

void show(TreeNode* node) {
	printf("%c\t", node->data);
}

void levelOrderTree(BinaryTree* tree) {
	if (tree == NULL || tree->root == NULL)
		return;
	TreeNode* queue[MAXSIZE];
	int front = 0, rear = 0;
	queue[0] = tree->root;
	++rear;
	while (front!=rear) {
		TreeNode* node = queue[front];
		front = (front + 1) % MAXSIZE;
		show(node);
		if (node->left) {
			queue[rear] = node->left;
			rear = (rear + 1) % MAXSIZE;
		}
		if (node->right) {
			queue[rear] = node->right;
			rear = (rear + 1) % MAXSIZE;
		}
	}
}

static void preNode(TreeNode* node) {
	if (node == NULL)
		return;
	show(node);
	preNode(node->left);
	preNode(node->right);
}

void preOrderTree(BinaryTree* tree) {
	if (tree) {
		preNode(tree->root);
	}
}

static void inNode(TreeNode*node) {
	if (node == NULL)
		return;
	inNode(node->left);
	show(node);
	inNode(node->right);
}

void inOrderTree(BinaryTree* tree) {
	if (tree) {
		inNode(tree->root);
	}
}

static void postNode(TreeNode* node) {
	if (node == NULL)
		return;
	postNode(node->left);
	postNode(node->right);
	show(node);
}

void postOrderTree(BinaryTree* tree) {
	if (tree) {
		postNode(tree->root);
	}
}