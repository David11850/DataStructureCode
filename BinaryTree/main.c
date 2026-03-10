//二叉树的基本操作，以及广度优先遍历（层级遍历、队列）、深度优先遍历（前序、中序、后序、栈）
#include"binaryTree.h"

static void initTestTree(BinaryTree*tree) {
	TreeNode* nodeA = createNode('A');
	TreeNode* nodeB = createNode('B');
	TreeNode* nodeC = createNode('C');
	TreeNode* nodeD = createNode('D');
	TreeNode* nodeE = createNode('E');
	TreeNode* nodeF = createNode('F');
	TreeNode* nodeG = createNode('G');
	TreeNode* nodeH = createNode('H');
	TreeNode* nodeK = createNode('K');

	tree->root = nodeA;
	++tree->num;
	tree = insert(tree, nodeA, nodeB, nodeE);
	tree = insert(tree, nodeB, NULL, nodeC);
	tree = insert(tree, nodeC, nodeD, NULL);
	tree = insert(tree, nodeE, NULL, nodeF);
	tree = insert(tree, nodeF, nodeG, NULL);
	tree = insert(tree, nodeG, nodeH, nodeK);
}

void test1() {//成功！
	BinaryTree* tree = creatTree();
	initTestTree(tree);
	levelOrderTree(tree);
	printf("\n");
	preOrderTree(tree);
	printf("\n");
	inOrderTree(tree);
	printf("\n");
	postOrderTree(tree);
	printf("\n");

	destroyTree(tree);
}



int main() {
	test1();

	return 0;
}