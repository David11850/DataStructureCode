#include"DoubleLoopLinkList.h"

void test1() {
	DLtable* table = malloc(sizeof(DLtable));
	init(table);
	for (int i = 0; i < 5; ++i) {
		push_back(table, i + 10);
	}
	showList(table);
	push_front(table, 999);
	showList(table);
	delValue(table, 999);
	showList(table);
	pop_back(table);
	pop_front(table);
	showList(table);
	destroyList(table);
}


int main() {
	test1();

	return 0;
}