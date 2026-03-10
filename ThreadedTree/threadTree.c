#include"threadTree.h"

threadedTree* creatTree() {
	threadedTree* tree = malloc(sizeof(threadedTree));
	tree->root = NULL;
	tree->count = 0;
	return tree;
}

static void destroyNode(threadedTree*tree,treeNode* node) {
	if (node) {
		if(node->ltag==0)
			destroyNode(tree,node->left);
		if (node->rtag == 0)
			destroyNode(tree,node->right);
		free(node);
		--tree->count;
	}
}

void destroyTree(threadedTree* tree) {
	if (tree) {
		treeNode* node = tree->root;
		destroyNode(tree,node);
	}
	printf("Num:%d\n", tree->count);
	free(tree);
}

void initTree(threadedTree* tree, treeNode* root) {
	if (tree && root) {
		tree->root = root;
		tree->count = 1;
	}
}

treeNode* createTreeNode(elem_t value) {
	treeNode* node = malloc(sizeof(treeNode));
	node->data = value;
	node->left = node->right = NULL;
	node->ltag = node->rtag = 0;
	return node;
}

void insertNode(threadedTree* tree, treeNode* root, treeNode* left, treeNode* right) {
	if (tree && root) {
		root->left = left;
		root->right = right;
		if (left) ++tree->count;
		if (right) ++tree->count;
	}
}

void visitNode(treeNode* node) {
	if (node) {
		printf("%c ", node->data);
	}
}

static treeNode* prev = NULL;
static void threadNode(treeNode* node) {
	if (node) {
		threadNode(node->left);

		if (node->left == NULL) {//当前结点的前驱
			node->left = prev;
			node->ltag = 1;
		}
		if (prev && prev->right == NULL) {//上个结点的后继
			prev->right = node;
			prev->rtag = 1;
		}
		prev = node;

		threadNode(node->right);
	}
}

void threadTree(threadedTree* tree) {
	if (tree) {
		treeNode* node = tree->root;
		prev = NULL;
		threadNode(node);//递归线索化
		prev->right = NULL;//尾节点处理
		prev->rtag = 1;
	}
}

void inorderTreadedTree(threadedTree* tree) {
	if (tree) {
		treeNode* node = tree->root;
		while (node->ltag == 0) {//到达极左
			node = node->left;
		}
		while (node) {//线性遍历，而非递归遍历（bfs/dfs），这就是线索化的作用，避免过深的树的递归导致栈溢出
			visitNode(node);
			if (node->rtag == 1)
				node = node->right;//到达后继结点
			else{
				node = node->right;
				while (node && node->ltag == 0) {//到达极左，重新开始中序遍历
					node = node->left;
				}
			}
		}
	}
}