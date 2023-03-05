#pragma once

typedef struct nodetag {
	int data;
	nodetag* next;
	nodetag* prev; //若单向链表，只需注释掉此行即可
} node;