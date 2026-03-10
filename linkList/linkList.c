//实现所有单链表！ 带头节点的单链表、带头指针的单链表+无头的链表、无头单链表
#include"linkList.h"

/*静态函数*/
static void insert(Lnode* prev, elem_t value) {		//插入操作 只需要知道前置结点与待插入数据(前置结点思想)
	Lnode* temp = malloc(sizeof(Lnode));
	if (temp == NULL)
		return;
	temp->data = value;
	temp->next = prev->next;		//备份思想
	prev->next = temp;
}

static void delNode(Lnode* prev) {		//删除某个结点，需要知道它的前置结点(前置结点思想)
	Lnode* temp = prev->next;			//temp为待删除结点
	prev->next = temp->next;			
	free(temp);
}

static void show(const Lnode* start) {		//从指定结点位置开始打印链表
	while (start) {
		printf("%d ", start->data);
		start = start->next;
	}
	printf("\n");
}

/*带头节点的单链表 函数接口*/
void insertHead(LinkTable* table, elem_t value) {
	Lnode* prev = table->header;		//头插法，前置结点时链表头中包含的那个头结点header
	insert(prev, value);				//调用封装的静态函数做插入操作，传入待插入位置的前置结点
	table->num++;						//元素个数加1
}

void insertTail(LinkTable* table, elem_t value) {
	Lnode* prev = table->header;
	while (prev->next) {		//找到链表的最后一个结点
		prev = prev->next;
	}
	insert(prev, value);		//调用封装的静态函数做插入操作，传入待插入位置的前置结点
	table->num++;				//元素个数加1
}

void insertPos(LinkTable* table, int pos, elem_t value) {
	if (pos<0 || pos>table->num) {		//插入位置的合法性检查
		printf("insertPos(): Invalid position to insert\n");
		return;
	}
	Lnode* prev = table->header;
	while (pos > 0) {		//找到前置结点
		prev = prev->next;
		--pos;
	}
	insert(prev, value);
	table->num++;
}

void showList(LinkTable* table) {
	Lnode* start = table->header->next;
	show(start);
}

void deleteList(LinkTable* table) {
	Lnode* prev = table->header;
	while (prev->next) {
		delNode(prev);
		--table->num;
	}
}


/*带头指针的单链表 函数接口*/
void insertHeadList(LinkList* list, elem_t value) {
	Lnode dummy;		//虚拟链表头
	dummy.next = list->ptr_Lnode;	//前置结点
	Lnode* prev = &dummy;
	insert(prev, value);		//前置结点插入函数（已封装）
	list->ptr_Lnode = dummy.next;	//更新表头的指针域数据
	++list->num;
}

void insertTailList(LinkList* list, elem_t value) {
	Lnode dummy;
	dummy.next = list->ptr_Lnode;
	Lnode* prev = &dummy;
	while (prev->next) {	//找到尾节点
		prev = prev->next;
	}
	insert(prev, value);
	list->ptr_Lnode = dummy.next;
	++list->num;
}

void insertPosList(LinkList* list, int pos, elem_t value) {
	Lnode dummy;
	dummy.next = list->ptr_Lnode;
	Lnode* prev = &dummy;
	for (int i = 0; i < pos; ++i) {
		prev = prev->next;
	}
	insert(prev, value);
	list->ptr_Lnode = dummy.next;
	++list->num;
}

void showLinkList(LinkList* list) {
	Lnode dummy;
	dummy.next = list->ptr_Lnode;
	Lnode* prev = &dummy;
	show(prev->next);
}

void deleteValueLinkList(LinkList* list, elem_t value) {
	Lnode dummy;
	dummy.next = list->ptr_Lnode;
	Lnode* prev = &dummy;
	for (int i = 1; i < list->num; ++i) {
		prev = prev->next;
		if (prev->next->data == value) {
			delNode(prev);
			--list->num;
			break;
		}
	}
	list->ptr_Lnode = dummy.next;
}

void deleteLinkList(LinkList* list) {
	Lnode dummy;
	dummy.next = list->ptr_Lnode;
	Lnode* prev = &dummy;
	while (prev->next) {
		delNode(prev);
		--list->num;
	}
	list->ptr_Lnode = dummy.next;
}


/*无头单链表*/
Lnode* insertHeadNoHead(Lnode* ptr, elem_t value) {
	Lnode dummy;	//虚拟头结点
	dummy.next = ptr;
	Lnode* prev = &dummy;
	insert(prev, value);
	return dummy.next;	//更新指针
}

Lnode* insertTailNoHead(Lnode* ptr, elem_t value) {
	Lnode dummy;
	dummy.next = ptr;
	Lnode* prev = &dummy;
	while (prev->next) {
		prev = prev->next;
	}
	insert(prev, value);
	return dummy.next;
}

Lnode* insertPosNoHead(Lnode* ptr, int pos, elem_t value) {
	if (pos < 0)
		return ptr;
	Lnode dummy;
	dummy.next = ptr;
	Lnode* prev = &dummy;
	for (int i = 0; i < pos; ++i) {
		prev = prev->next;
	}
	insert(prev, value);
	return dummy.next;
}

void showNoHead(Lnode* ptr) {
	show(ptr);
}

Lnode* deleteValueNoHead(Lnode* ptr, elem_t value) {
	Lnode dummy;
	dummy.next = ptr;
	Lnode* prev = &dummy;
	while (prev->next) {
		if (prev->next->data == value) {
			delNode(prev);
			break;
		}
		prev = prev->next;
	}
	return dummy.next;
}

void deleteNoHead(Lnode* ptr) {
	Lnode dummy;
	dummy.next = ptr;
	Lnode* prev = &dummy;
	while (prev->next) {
		delNode(prev);
	}
}