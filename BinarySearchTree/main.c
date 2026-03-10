#include"binarySearchTree.h"

void test() {//¶þ²æËÑË÷Ê÷ ³É¹¦£¡
	BSTree* tree = createBinarySearchTree();
	insertBinarySearchTree(tree, 10);
	insertBinarySearchTree(tree, 12);
	insertBinarySearchTree(tree, 2);
	insertBinarySearchTree(tree, 30);
	insertBinarySearchTree(tree, 13);
	insertBinarySearchTree(tree, 3);
	insertBinarySearchTree(tree, 21);
	inorderBinarySearchTree(tree);
	releaseBinarySearchTree(tree);
}

int main() {
	test();

	return 0;
}