#include"avlTree.h"

void test() {//成功（艰难）
	avlTree* tree = createTree();
	pushNode(tree, 10);
	pushNode(tree, 12);
	pushNode(tree, 3);
	pushNode(tree, 13);
	pushNode(tree, 20);
	pushNode(tree, 39);
	pushNode(tree, 110);
	pushNode(tree, 2);
	visit(tree);
	printf("---\n");
	popNode(tree, 110);
	popNode(tree, 20);
	visit(tree);
	releaseTree(tree);
}

int main() {
	test();
	return 0;
}