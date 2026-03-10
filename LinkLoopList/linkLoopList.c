#include"linkLoopList.h"

static void insert(LinkTable* table, Lnode* prev, elem_t v) {
	Lnode* node = malloc(sizeof(Lnode));
	node->data = v;
	node->next = prev->next;
	prev->next = node;
	if (prev == table->rear) {//尾插更新尾指针
		table->rear = node;
	}
	table->num++;
}

static void deleteNode(LinkTable* table, Lnode* prev) {
	if (prev == table->rear) {//禁止删除表头中的首结点
		return;
	}
	Lnode* node = prev->next;
	prev->next = node->next;
	if (node == table->rear) {//删除尾结点，更新尾指针
		table->rear = prev;
	}
	//printf("\tdelete node:%d", node->data);
	free(node);
	table->num--;
}

void initLinkLoopList(LinkTable* table) {
	table->header.next = &table->header;
	table->rear = &table->header;
	table->num = 0;
}

void InsertHeadLinkLoopTable(LinkTable* table, elem_t v) {
	Lnode* prev = &table->header;
	insert(table, prev, v);
}

void insertTailLinkLoopTable(LinkTable* table, elem_t v) {
	Lnode* prev = table->rear;
	insert(table, prev, v);
}

void showLinkLoopTable(LinkTable* table) {
	Lnode* node = table->header.next;
	while (node != &table->header) {
		printf("\t%d", node->data);
		node = node->next;
	}
	printf("\n");
}

void deleteValueLinkLoopTable(LinkTable* table, elem_t v) {
	Lnode* prev = &table->header;
	while (prev->next != &table->header) {
		if (prev->next->data == v) {
			deleteNode(table, prev);
			break;
		}
		prev = prev->next;
	}
}

void destroyLinkLoopTable(LinkTable* table) {
	Lnode* prev = &table->header;
	while (prev->next != &table->header) {
		deleteNode(table, prev);
	}
	table->rear = &table->header;
	printf("Num:%d\n", table->num);
}