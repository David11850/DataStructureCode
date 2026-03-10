#include"RBtree.h"

RBTree* createTree() {
	RBTree* tree = (RBTree*)malloc(sizeof(RBTree));
	tree->root = NULL;
	tree->size = 0;
	return tree;
}

static void releaseNode(RBTree* tree, RBNode* node) {
	if (!node) return;
	if (node->left) releaseNode(tree, node->left);
	if (node->right) releaseNode(tree, node->right);
	free(node);
	--tree->size;
}

void releaseTree(RBTree* tree) {
	if (!tree) return;
	releaseNode(tree, tree->root);
	printf("Node:%d\n", tree->size);
	tree->root = NULL;
	free(tree);
}

static RBNode* createNode(RBKey key) {
	RBNode* node = (RBNode*)malloc(sizeof(RBNode));
	if (node == NULL) return NULL;
	node->key = key;
	node->color = RED;
	node->left = node->right = node->parent = NULL;
	return node;
}

/* 红黑树的插入*/
/* 将x进行左旋，将左、右、父节点进行更新
*      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(左旋)-->           / \
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
*/
static void leftRotate(RBTree* tree, RBNode* x) {
	RBNode* y = x->right;
	x->right = y->left;
	if (y->left)y->left->parent = x;
	y->parent = x->parent;
	if (x->parent) {
		if (x->parent->left == x)x->parent->left = y;
		else x->parent->right = y;
	}
	else tree->root = y;
	y->left = x;
	x->parent = y;
}

/* 将y进行右旋，将左、右、父节点进行更新
 *           py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(右旋)-->            /  \
 *        x   ry                           lx   y
 *       / \                                   / \
 *      lx  rx                                rx  ry
 * */
static void rightRotate(RBTree* tree, RBNode* y) {
	RBNode* x = y->left;
	y->left = x->right;
	if (x->right) x->right->parent = y;
	x->parent = y->parent;
	if (y->parent) {
		if (y->parent->left == y) y->parent->left = x;
		else y->parent->right = x;
	}
	else tree->root = x;
	x->right = y;
	y->parent = x;
}

static void changePtr(RBNode** a, RBNode** b) {
	RBNode* temp = *a;
	*a = *b;
	*b = temp;
}

/* 红黑树的插入 node
* 维护红黑树五条性质的过程（注意逻辑完备性）
* 1.父节点是黑色： 无需调整
* 2.父节点是红色： ！红红！ 需要调整，此时祖父结点必为黑色
* 2.1 叔叔节点是红色： 叔叔变黑 父节点变黑 祖父结点变红 继续判断祖父结点（node=grandparent;）
* 2.2 叔叔结点是黑色：
* 2.2.1 父亲在左 叔叔在右
*	2.2.1.1 node在左：对祖父右旋 父亲变黑 祖父变红
*	2.2.1.2 node在右：先对父亲结点左旋 转为node在左 即2.2.1.1
* 2.2.2 父亲在右 叔叔在左
*	2.2.2.1 node在左：对父亲右旋 转为node在右 即2.2.2.2
*	2.2.2.2 node在右：对祖父结点左旋 父亲变黑 祖父变红
*/
void insertNode(RBTree* tree, RBKey key) {
	/*1.在堆段内存上 创建红色结点*/
	RBNode* node = createNode(key);
	if (node == NULL) return;
	++tree->size;

	/*2.使用快慢指针 找到在二叉搜索树中的待插入位置*/
	RBNode* cur = tree->root, * pre = NULL;
	while (cur) {
		pre = cur;
		if (key < cur->key) {
			cur = cur->left;
		}
		else if (key > cur->key) {
			cur = cur->right;
		}
		else {
			printf("Has the same key value node\n");
			free(node);
			return;
		}
	}
	if (pre == NULL) {//空树
		tree->root = node;
		node->color = BLACK;
		return;
	}

	/*3.插入新节点*/
	node->parent = pre;
	if (key < pre->key) pre->left = node;
	else pre->right = node;

	/*4.维护红黑树五条性质*/
		/*1. 父亲是黑色*/
	if (node->parent->color == BLACK) return;
	/*2. 父亲是红色*/
	RBNode* uncle, * parent = node->parent, * grandparent;
	while (parent && node->parent->color == RED) {
		parent = node->parent;
		grandparent = parent->parent;
		if (!grandparent) {
			parent->color = BLACK;
			return;
		}
		if (grandparent->left == parent)uncle = grandparent->right;
		else uncle = grandparent->left;
		/* 2.1 叔叔结点是红色*/
		if (uncle && uncle->color == RED) {
			uncle->color = BLACK;
			parent->color = BLACK;
			grandparent->color = RED;
			node = grandparent;
			parent = grandparent->parent;
			continue;
		}
		/* 2.2 叔叔结点是黑色*/
		else {
			if (grandparent->left == parent) {
				if (parent->right == node) {
					leftRotate(tree, parent);
					changePtr(&node, &parent);
				}
				rightRotate(tree, grandparent);
				parent->color = BLACK;
				grandparent->color = RED;
			}
			else {
				if (parent->left == node) {
					rightRotate(tree, parent);
					changePtr(&node, &parent);
				}
				leftRotate(tree, grandparent);
				parent->color = BLACK;
				grandparent->color = RED;
			}
		}
	}
	tree->root->color = BLACK;
}




/*红黑树的删除
* 1.找到待删除结点
* 2.找到替换结点
* 3.判断删除后是否满足红黑树性质
*	3.1 红黑 / 黑红 ：直接替换
*	3.2 黑黑：进入修正，看兄弟结点的颜色
*		3.2.1 兄弟结点为红色：通过旋转变为黑色
*		3.2.2 兄弟结点为黑色
*			3.2.2.1 兄弟结点的孩子结点全为黑色：兄弟结点变为红色 更新待处理结点为父节点 重新进入循环
*			3.2.2.2 兄弟结点内测孩子为红色：旋转转为外侧红
*			3.2.2.3 兄弟结点为黑色 并且有外侧红色孩子：旋转父节点 兄弟结点继承父节点颜色 父节点变黑 红色孩子变黑 完成双黑结点的处理
*/

static void delRBNodeUP(RBTree* tree, RBNode* node, RBNode* parent) {
	RBNode* bro;
	while ((!node || node->color == BLACK )&& node != tree->root) {
		if (parent->left == node) {//bro在右边
			bro = parent->right;
			//3.2.1 兄弟颜色为红色 转为黑色
			if (bro->color == RED) {
				parent->color = RED;
				bro->color = BLACK;
				leftRotate(tree, parent);
				parent = node->parent;
				bro = parent->right;
			}
			//3.2.2 兄弟结点为黑色
			//3.2.2.1 兄弟结点孩子全黑:兄弟变红 继续处理父亲
			if ((!bro->left || bro->left->color == BLACK) && (!bro->right || bro->right->color == BLACK)) {
				bro->color = RED;
				node = parent;
				parent = node->parent;
			}
			else {
				//3.2.2.2 兄弟结点内测孩子为红：转为外侧红
				if (bro->left && bro->left->color == RED) {
					bro->color = RED;
					bro->left->color = BLACK;
					rightRotate(tree, bro);
					bro = parent->right;
				}
				//3.2.2.3 兄弟结点外侧孩子为红：直接旋转 完成双黑结点的解决
				bro->color = parent->color;
				parent->color = BLACK;
				bro->right->color = BLACK;
				leftRotate(tree, parent);
				parent = node->parent;
				node = tree->root;
			}
		}
		else {//bro在左边
			bro = parent->left;
			//兄弟结点为红
			if (bro->color == RED) {
				bro->color = BLACK;
				parent->color = RED;
				rightRotate(tree, parent);
				parent = node->parent;
				bro = parent->left;
			}
			//兄弟结点孩子权威黑
			if ((!bro || bro->left->color == BLACK) && (!bro || bro->right->color == BLACK)) {
				bro->color = RED;
				node = parent;
				parent = node->parent;
			}
			else {
				//内测红
				if (bro->right && bro->right->color == RED) {
					bro->color = RED;
					bro->right->color = BLACK;
					leftRotate(tree, bro);
					bro = parent->left;
				}
				//外侧红
				bro->color = parent->color;
				parent->color = BLACK;
				bro->left->color = BLACK;
				rightRotate(tree, parent);
				parent = node->parent;
				node = tree->root;
			}
		}
	}
	if(node)
		node->color = BLACK;
}

void deleteNode(RBTree* tree, RBKey key) {
	//寻找待删除结点node
	RBNode* node = tree->root, * del, * instead;
	while (node) {
		if (node->key < key) {
			node = node->right;
		}
		else if (node->key > key) {
			node = node->left;
		}
		else {
			break;
		}
	}
	if (node->left == NULL || node->right == NULL) {	//度为0/1
		del = node;
	}
	else {		//度为2 找后继结点为删除结点的替罪羊
		del = node->right;
		while (del->left) {
			del = del->left;
		}
	}

	//找到待删除结点 node 和真实删除的结点 del 找到替代结点instead
	if (del->left) {
		instead = del->left;
	}
	else {
		instead = del->right;
	}

	//找到替代结点instead 进行替换处理
	if (del->parent) {
		if (del->parent->left == del) del->parent->left = instead;
		else del->parent->right = instead;
	}else {
		tree->root = instead;
	}
	if (instead) {
		instead->parent = del->parent;
	}

	if (node != del) {
		node->key = del->key;
	}

	if (del->color == BLACK) {
		RBNode* parent = del->parent;
		delRBNodeUP(tree, instead, parent);
	}
	free(del);
	--tree->size;
}



static void showNode(RBNode* node, char dir) {
	if (!node) return;
	if (!node->parent) printf("%d %c : root\n", node->key, node->color);
	else printf("%d %c : %d's %c\n", node->key, node->color == RED ? 'R' : 'B', node->parent->key, dir);
	showNode(node->left, 'L');
	showNode(node->right, 'R');
}

void showTree(RBTree* tree) {
	if (!tree) return;
	showNode(tree->root, 'M');
	printf("\n");
}