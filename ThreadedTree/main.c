#include"threadTree.h"

static threadedTree* initTestTree() {//成功（艰难版本）！线索二叉树
	threadedTree* tree = creatTree();

	treeNode* nodeA = createTreeNode('A');
	treeNode* nodeB = createTreeNode('B');
	treeNode* nodeC = createTreeNode('C');
	treeNode* nodeD = createTreeNode('D');
	treeNode* nodeE = createTreeNode('E');
	treeNode* nodeF = createTreeNode('F');
	treeNode* nodeG = createTreeNode('G');
	treeNode* nodeH = createTreeNode('H');
	treeNode* nodeK = createTreeNode('K');

	/*
								a
							b       e
						       c		f
							d		   g
									  h k

	*/


	initTree(tree, nodeA);
	insertNode(tree, nodeA, nodeB, nodeE);
	insertNode(tree, nodeB, NULL, nodeC);
	insertNode(tree, nodeC, nodeD, NULL);
	insertNode(tree, nodeE, NULL, nodeF);
	insertNode(tree, nodeF, nodeG, NULL);
	insertNode(tree, nodeG, nodeH, nodeK);
	return tree;
}

void test() {
	threadedTree* tree = initTestTree();
	threadTree(tree);
	inorderTreadedTree(tree);
	destroyTree(tree);
}



int main() {
	test();

	return 0;
}