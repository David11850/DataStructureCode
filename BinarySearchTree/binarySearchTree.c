#include"binarySearchTree.h"

BSTree* createBinarySearchTree() {
	BSTree* tree = malloc(sizeof(BSTree));
	tree->root = NULL;
	tree->count = 0;
	return tree;
}

static void delNode(BSTree* tree, BSNode* node) {
	if (node == NULL)
		return;
	delNode(tree, node->left);
	delNode(tree, node->right);
	free(node);
	--tree->count;
}

void releaseBinarySearchTree(BSTree* tree) {
	if (tree == NULL)
		return;
	delNode(tree, tree->root);
	printf("\nNum:%d\n", tree->count);
}

static BSNode* insertNode(BSNode* node, elem_t value) {
	if (node == NULL) {
		BSNode* newNode = malloc(sizeof(BSNode));
		newNode->data = value;
		newNode->left = newNode->right = NULL;
		return newNode;
	}
	if (value < node->data) {
		node->left = insertNode(node->left, value);
	}
	else if (value > node->data) {
		node->right = insertNode(node->right, value);
	}
	return node;
}

/*二叉搜索树的插入  重点函数   左小右大！*/
void insertBinarySearchTree(BSTree* tree, elem_t value) {
	tree->root=insertNode(tree->root, value);
	++tree->count;
}

void visitNode(BSNode* node) {
	if (node) {
		printf("\t%d", node->data);
	}
}

/*中序遍历二叉树 通用函数  左根右访问顺序*/
static void inorderNode(BSNode* node) {
	if (node == NULL)
		return;
	inorderNode(node->left);
	visitNode(node);
	inorderNode(node->right);
}

/*中序遍历二叉搜索树  重点函数*/
void inorderBinarySearchTree(BSTree* tree) {
	if (tree == NULL)
		return;
	inorderNode(tree->root);
}