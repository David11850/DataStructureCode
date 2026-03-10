#include"huffmanTree.h"

void test() {//构建哈夫曼树、构建哈夫曼编码 成功！
	char ch[] = { 'a','g','m','t','e','h','_','i','s' };
	int we[] = { 1,1,1,1,2,2,3,3,5 };

	int n = sizeof(we) / sizeof(we[0]);
	huffmanTree tree = initTree(we, n);
	tree = createHuffmanTree(tree, n);
	
	for (int i = 0; i < 2 * n - 1; ++i) {
		printf("%d %c:%d\t%d\t%d\t%d\n",i, ch[i], tree[i].weight, tree[i].parent, tree[i].lchild, tree[i].rchild);
	}
	printf("\n");

	huffmanCode* code = createHuffmanCode(tree, n);
	for (int i = 0; i < n; ++i) {
		printf("%c:%s\n", ch[i], code[i]);
	}

	releaseCode(code, n);
	releaseTree(tree);
}

int main() {
	test();
	return 0;
}