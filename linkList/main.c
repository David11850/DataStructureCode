#include"linkList.h"

//测试带头节点的单链表各项函数接口功能 成功！
void test1() {
	LinkTable* table = (LinkTable*)malloc(sizeof(LinkTable));
	table->num = 0;
	table->header = (Lnode*)malloc(sizeof(Lnode));
	table->header->next = NULL;

	for (int i = 0; i < 10; ++i) {
		insertHead(table, i + 10);
	}
	showList(table);
	insertTail(table, 999);
	showList(table);
	insertPos(table, 5, 0);
	showList(table);
	deleteList(table);
	showList(table);
	free(table->header);
}

//测试带头指针的单链表各项函数接口功能 成功！
void test2() {
	LinkList* list = malloc(sizeof(LinkList));
	list->ptr_Lnode = NULL;
	list->num = 0;

	for (int i = 0; i < 5; ++i) {
		insertHeadList(list, i + 10);
	}
	showLinkList(list);
	insertTailList(list, 999);
	showLinkList(list);
	insertPosList(list, 3, 0);
	showLinkList(list);
	deleteValueLinkList(list, 0);
	showLinkList(list);
	deleteLinkList(list);
	free(list);
}

//测试无头单链表的各项函数接口功能（附带调试过程，笑 ） 成功！
void test3() {
	Lnode* node = malloc(sizeof(Lnode));		//栈段上局部变量，无需手动释放
	node->data = 10;
	node->next = NULL;

	for (int i = 1; i < 5; ++i) {
		node=insertHeadNoHead(node, i + 10);
	}
	showNoHead(node);
	node=insertTailNoHead(node, 999);		
	showNoHead(node);
	node=insertPosNoHead(node, 4, 0);
	showNoHead(node);
	node=deleteValueNoHead(node, 0);
	showNoHead(node);
	deleteNoHead(node);
}


int main() {
	//test1();
	//test2();
	test3();

	return 0;
}