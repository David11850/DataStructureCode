#include"DoubleLoopLinkList.h"

static void insert(Lnode* new_node, Lnode* prev, Lnode* next) {
	next->prev = new_node;
	new_node->next = next;
	new_node->prev = prev;
	prev->next = new_node;
}

static void delNode(Lnode* prev, Lnode* next) {
	next->prev = prev;
	prev->next = next;
}

void init(DLtable* table) {
	table->header.next = &table->header;
	table->header.prev = &table->header;
	table->num = 0;
}

void push_front(DLtable* table, elem_t value) {
	Lnode* new_node = malloc(sizeof(Lnode));
	new_node->data = value;
	insert(new_node, &table->header, table->header.next);
	table->num++;
}

void push_back(DLtable* table, elem_t value) {
	Lnode* new_node = malloc(sizeof(Lnode));
	new_node->data = value;
	insert(new_node, table->header.prev, &table->header);
	++table->num;
}

void pop_front(DLtable* table) {
	if (table->header.next == &table->header) {
		printf("Empty Link List\n");
		return;
	}
	Lnode* temp = table->header.next;
	delNode(temp->prev, temp->next);
	free(temp);
	--table->num;
}

void pop_back(DLtable* table) {
	if (table->header.prev == &table->header) {
		printf("Empty Link List\n");
		return;
	}
	Lnode* temp = table->header.prev;
	delNode(temp->prev, temp->next);
	free(temp);
	--table->num;
}

void delValue(DLtable* table, elem_t value) {
	if (table->header.next == &table->header) {
		printf("Empty Link List\n");
		return;
	}
	Lnode* temp = table->header.next;
	while (temp != &table->header) {
		if (temp->data == value) {
			delNode(temp->prev, temp->next);
			free(temp);
			--table->num;
			return;
		}
		temp = temp->next;
	}
	printf("Not Found %d\n", value);
}

void destroyList(DLtable* table) {
	if (table->header.next == &table->header) {
		printf("Empty Link List\n");
		return;
	}
	Lnode* temp = table->header.next;
	while (temp != &table->header) {
		Lnode* next = temp->next;
		free(temp);
		temp = next;
		--table->num;
	}
	printf("Num:%d\n", table->num);
}

void showList(DLtable* table) {
	Lnode* temp = table->header.next;
	printf("List:\n");
	while (temp != &table->header) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}