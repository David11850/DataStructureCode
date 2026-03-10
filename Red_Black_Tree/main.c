#include"RBtree.h"

void test1() {//红黑树的插入 成功！
	int data[] = { 55, 40, 65, 60, 75, 57, 63, 56 };
	RBTree* tree = createTree();
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
		insertNode(tree, data[i]);
	}
	showTree(tree);
	releaseTree(tree);
}

void test2() {  //红黑树的删除 成功 //艰难！
	int data[] = { 55, 40, 65, 60, 75, 57, 63, 56 };
	RBTree* tree = createTree();
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
		insertNode(tree, data[i]);
	}
	showTree(tree);
	deleteNode(tree, 55);
	showTree(tree);
	deleteNode(tree, 40);
	deleteNode(tree, 63);
	showTree(tree);
	releaseTree(tree);
}

int main() {
	test2();
	return 0;
}