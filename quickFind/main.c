#include"quickFind.h"

void test() {//并查集 快查 成功
	quickFindSet* set = createSet(10);
	char ch[] = { 'a','s','d','l','g','h','j' };
	insert(set, ch, 7);
	search(set, 'a', 'd') ? printf("In a group\n") : printf("NOT in a group\n");
	unino(set, 'a', 'd');
	search(set, 'a', 'd') ? printf("In a group\n") : printf("NOT in a group\n");

	releaseSet(set);
}

int main() {
	test();
	return 0;
}