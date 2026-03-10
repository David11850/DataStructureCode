#include"avlTree.h"

avlTree* createTree() {
	avlTree* tree = (avlTree*)malloc(sizeof(avlTree));
	tree->root = NULL;
	tree->count = 0;
	return tree;
}

static void delNode(avlTree* tree, avlNode* node) {
	if (node) {
		delNode(tree, node->left);
		delNode(tree, node->right);
		free(node);
		tree->count--;
	}
}

void releaseTree(avlTree*tree) {
	delNode(tree, tree->root);
	printf("Num:%zd\n", tree->count);
}

static avlNode* addNode(elem_t value) {
	avlNode* node = (avlNode*)malloc(sizeof(avlNode));
	node->data = value;
	node->left = node->right = NULL;
	node->height = 1;
	return node;
}

static size_t my_max(size_t a, size_t b) {
	return a > b ? a : b;
}

static size_t getHeight(avlNode* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return node->height;
	}
}

static int getBalance(avlNode* node) {
	if (node == NULL)
		return 0;
	else {
		return getHeight(node->left) - getHeight(node->right);
	}
}

/*左旋
			x
		b		y
	d	  e	    	f
*/

static avlNode* leftRotate(avlNode* node) {
	avlNode* x = node, * y = x->right;
	x->right = y->left;
	y->left = x;

	x->height = my_max(getHeight(x->left), getHeight(x->right))+1;
	y->height = my_max(getHeight(y->left), getHeight(y->right))+1;
	return y;
}

//右旋
static avlNode* rightRotate(avlNode* node) {
	avlNode* x = node, * y = x->left;
	x->left = y->right;
	y->right = x;

	x->height = my_max(getHeight(x->left), getHeight(x->right))+1;
	y->height = my_max(getHeight(y->left), getHeight(y->right))+1;
	return y;
}

static avlNode* push(avlNode* node,elem_t value) {
	//递归的“递”的过程——用于找到在二叉（平衡）搜索树中的插入位置
	if (node == NULL) {
		avlNode* newnode = addNode(value);
		return newnode;
	}
	if (value < node->data) {
		node->left = push(node->left, value);
	}
	else if (value > node->data) {
		node->right = push(node->right, value);
	}
	else {
		return node;
	}

	//递归的“归”的过程——用于更新各个结点的高度height 与 判断各个节点是否平衡
	node->height = my_max(getHeight(node->left), getHeight(node->right)) + 1;//更新高度
	//判断是否平衡
	int balance = getBalance(node);
	if (balance < -1) {//右重
		if (value < node->right->data) {//RL
			node->right = rightRotate(node->right);
		}
		return leftRotate(node);//RR
	}
	if (balance > 1) {//左重
		if (value > node->left->data) {//LR
			node->left = leftRotate(node->left);
		}
		return rightRotate(node);//LL
	}
	return node;
}

void pushNode(avlTree* tree, elem_t value) {
	tree->root = push(tree->root, value);
	++tree->count;
}

static avlNode* pop(avlNode* node, elem_t value) {
	//递归的“递”过程 找要删除的结点的位置
	if (node == NULL) return NULL;
	if (value < node->data) {
		node->left = pop(node->left, value);
	}
	else if (value > node->data) {
		node->right = pop(node->right, value);
	}
	else {
		// 找到要删除的节点
		if (node->left == NULL) {
			// 只有右子树或没有子树
			avlNode* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			// 只有左子树
			avlNode* temp = node->left;
			free(node);
			return temp;
		}
		else {
			// 有两个子节点，找前驱
			avlNode* temp = node->left;
			while (temp->right != NULL) {
				temp = temp->right;
			}
			node->data = temp->data;
			node->left = pop(node->left, temp->data);
		}
	}

	//递归的“归”的过程，用于更新高度 和 判断是否平衡
	node->height = my_max(getHeight(node->left), getHeight(node->right)) + 1;
	//判断是否平衡
	if (getBalance(node) < -1) {//右重
		if (getBalance(node->right) > 0) {//RL
			node->right = rightRotate(node->right);
		}
		return leftRotate(node);//RR
	}
	else if (getBalance(node) > 1) {//左重
		if (getBalance(node->left) < 0) {//LR
			node->left = leftRotate(node->left);
		}
		return rightRotate(node);//LL
	}
	else//正常值 -1 0 1
		return node;
}

void popNode(avlTree* tree, elem_t value) {
	tree->root = pop(tree->root, value);
	--tree->count;
}

static void inorder(avlNode* node) {
	if (node == NULL) return;
	inorder(node->left);
	printf("<%d,%zd>\t", node->data, node->height);
	inorder(node->right);
}

void visit(avlTree* tree) {
	avlNode* temp = tree->root;
	inorder(temp);
}