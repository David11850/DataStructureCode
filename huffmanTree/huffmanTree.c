#include"huffmanTree.h"

huffmanTree* initTree(const int* ch, int n) {
	int m = 2 * n - 1;
	huffmanTree tree = malloc(sizeof(huffmanTreeNode) * m);
	if (tree == NULL) {
		return NULL;
	}

	for (int i = 0; i < m; ++i) {
		tree[i].weight = 0;
		tree[i].parent = tree[i].lchild = tree[i].rchild = -1;
	}

	for (int i = 0; i < n; ++i) {
		tree[i].weight = ch[i];
	}

	return tree;
}

static void findMini(huffmanTree tree, int n, int* s1, int* s2) {
	int ta = -1, tb = -1;
	//找到第一个可被选择的结点
	for (int i = 0; i <= n; ++i) {
		if (tree[i].parent == -1) {
			ta = i;
			break;
		}
	}
	//找到最小值s1
	for (int i = ta + 1; i <= n; ++i) {
		if (tree[i].parent == -1 && i != ta && tree[i].weight < tree[ta].weight) {
			ta = i;
		}
	}
	*s1 = ta;

	//找到第一个可被选择的结点
	for (int i = 0; i <= n; ++i) {
		if (tree[i].parent == -1 && (i!= ta)) {
			tb = i;
			break;
		}
	}
	//找到最小值s2
	for (int i = tb + 1; i <= n; ++i) {
		if (tree[i].parent == -1 && i!=ta && tree[i].weight < tree[tb].weight) {
			tb = i;
		}
	}
	*s2 = tb;
}

huffmanTree createHuffmanTree(huffmanTree tree, int n) {
	int m = 2 * n - 1, s1 = -1, s2 = -1;

	for (int i = n; i < m; ++i) {
		//查找到[0,i-1]中，parent==0 && 权值最小的两个结点
		findMini(tree, i - 1, &s1, &s2);

		tree[i].weight = tree[s1].weight + tree[s2].weight;
		tree[i].lchild = s1;
		tree[i].rchild = s2;
		tree[s1].parent = tree[s2].parent = i;
	}

	return tree;
}

void releaseTree(huffmanTree tree) {
	free(tree);
}

//
huffmanCode* createHuffmanCode(huffmanTree tree, int n) {
	huffmanCode* code = malloc(sizeof(huffmanCode) * n);

	char* temp = malloc(sizeof(char) * n);
	int start = n - 1;
	int t;
	int parent;

	for (int i = 0; i < n; ++i) {
		start = n - 1;
		parent = tree[i].parent;
		t = i;
		temp[start] = '\0';

		while (parent != -1) {
			--start;
			if (start < 0) {
				printf("start<0\n");
				return NULL;
			}
			temp[start] = (tree[parent].lchild == t ? '0' : '1');
			t = parent;
			parent = tree[t].parent;
		}

		code[i] = malloc(sizeof(char) * (n - start));
		strcpy(code[i], &temp[start]);
	}

	return code;
}

void releaseCode(huffmanCode* code, int n) {
	if (!code)
		return;
	for (int i = 0; i < n; ++i) {
		if (code[i]) {
			free(code[i]);
		}
	}
	free(code);
}