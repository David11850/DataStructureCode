#include"linkLoopList.h"

void test1() {
	LinkTable* table = malloc(sizeof(LinkTable));
	initLinkLoopList(table);
	for (int i = 0; i < 5; ++i) {
		InsertHeadLinkLoopTable(table, i + 10);
	}
	showLinkLoopTable(table);
	for (int i = 0; i < 5; ++i) {
		insertTailLinkLoopTable(table, i + 100);
	}
	showLinkLoopTable(table);
	deleteValueLinkLoopTable(table, 100);
	showLinkLoopTable(table);
	destroyLinkLoopTable(table);
	free(table);
}

int main() {
	test1();




	return 0;
}