#include <cstdio>
#include "node.h"
#include "linkedlist.h"
#include "bicirlinkedlist.h"

int main()
{
	printf("单向链表部分：\n");
	linkedlist ll;
	printf("遍历空表\n");
	ll.traverse();
	printf("从空表删除1\n");
	ll.traverse();
	printf("销毁空表\n");
	ll.destroy();
	printf("插入1\n");
	ll.insert(1);
	ll.traverse();
	printf("删除1\n");
	ll.del(1);
	ll.traverse();
	printf("从空表删除2\n");
	ll.del(2);
	ll.traverse();
	printf("插入1\n");
	ll.insert(1);
	ll.traverse();
	printf("插入2\n");
	ll.insert(2);
	ll.traverse();
	printf("删除2\n");
	ll.del(2);
	ll.traverse();
	printf("插入2\n");
	ll.insert(2);
	ll.traverse();
	printf("插入3\n");
	ll.insert(3);
	ll.traverse();
	printf("删除4\n");
	ll.del(4);
	ll.traverse();
	printf("删除1\n");
	ll.del(1);
	ll.traverse();
	printf("销毁表\n");
	ll.destroy();
	printf("\n双向链表部分：\n");

	bicirlinkedlist bcll;
	printf("遍历空表\n");
	bcll.traverse();
	printf("从空表删除1\n");
	bcll.traverse();
	printf("销毁空表\n");
	bcll.destroy();
	printf("插入1\n");
	bcll.insert(1);
	bcll.traverse();
	printf("删除1\n");
	bcll.del(1);
	bcll.traverse();
	printf("从空表删除2\n");
	bcll.del(2);
	bcll.traverse();
	printf("插入1\n");
	bcll.insert(1);
	bcll.traverse();
	printf("插入2\n");
	bcll.insert(2);
	bcll.traverse();
	printf("删除2\n");
	bcll.del(2);
	bcll.traverse();
	printf("插入2\n");
	bcll.insert(2);
	bcll.traverse();
	printf("插入3\n");
	bcll.insert(3);
	bcll.traverse();
	printf("删除4\n");
	bcll.del(4);
	bcll.traverse();
	printf("删除1\n");
	bcll.del(1);
	bcll.traverse();
	printf("销毁表\n");
	bcll.destroy();
	return 0;
}