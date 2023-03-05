#pragma once
#include <cstdio>
#include "node.h"

class linkedlist
{
public:
	linkedlist() { head = NULL; }
	void destroy();
	void insert(int val);
	void del(int val);
	int getval(node* addr);
	node* getprev(node* addr);
	node* getnext(node* addr);
	void traverse();
private:
	node* head;
};

void linkedlist::destroy()
{
	while (head != NULL) {
		node* del = head;
		head = head->next; //在删除del结点前，需先保存下一节点地址
		delete del;
	}
}

void linkedlist::insert(int val)
{
	node* newhead = new node();
	newhead->data = val;
	newhead->next = head;
	head = newhead; //在初始化完newhead->next后才可更新表头
}

void linkedlist::del(int val) {
	if (head == NULL) return;
	else if(head->data == val) {
		node* del = head; //更新表头前先记录被删表头
		head = head->next;
		delete del;
	}
	else {
		node* prev = head, *del; //prev最终为val对应结点的前驱（被删元素不是表头，故一定存在前驱）
		while (prev->next != NULL && prev->next->data != val) {
			prev = prev->next;
		}
		if (prev->next == NULL) return; //prev已在表尾，仍未找到val，即表中没有val，无需删除
		del = prev->next; //更新prev->next前先记录所删结点
		prev->next = prev->next->next;
		delete del;
	}
}

int linkedlist::getval(node* addr)
{
	return addr->data;
}

node* linkedlist::getprev(node* addr) {
	if (head == NULL || addr == NULL) return NULL;
	node* prev = head; //prev最终记录addr的前驱地址
	while (prev->next != addr && prev->next != NULL) prev = prev->next;
	if (prev->next == NULL) return NULL; //prev已为表底，不可能为前驱，说明addr不在表中
	return prev;
}

node* linkedlist::getnext(node* addr)
{
	if (addr != NULL) return addr->next;
	else return NULL;
}

void linkedlist::traverse()
{
	if (head == NULL) return;
	node* cur = head;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}