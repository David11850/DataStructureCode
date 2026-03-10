#include"quickUnino.h"

void test() {//并查集 成功！ 完结
	quickUninoSet* set = createSet(10);
	char ch[] = { 'w','e','r','t','y','u','i' };
	insert(set, ch, sizeof(ch) / sizeof(ch[0]));
	search(set, 'w', 'e') ? printf("in one set\n") : printf("NOT in onr set\n");
	unino(set, 'w', 'e');
	search(set, 'w', 'e') ? printf("in one set\n") : printf("NOT in onr set\n");
	releaseSet(set);
}

int main() {
	test();
	return 0;
}