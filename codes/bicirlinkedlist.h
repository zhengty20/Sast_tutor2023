#pragma once
#include <cstdio>
#include "node.h"

class bicirlinkedlist
{
public:
	bicirlinkedlist() { head = NULL; }
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

void bicirlinkedlist::destroy()
{
	if (head != NULL) {
		node* start = head, *del; //start记录最初的表头
		while (head->next != start) { //head指针
			del = head;
			head = head->next; //在删除del结点前，需先保存下一节点地址
			delete del;
		}
		delete head;
	}
}

void bicirlinkedlist::insert(int val)
{
	if (head == NULL) {
		head = new node();
		head->data = val;
		head->next = head->prev = head;
	}
	else{
		node* newhead = new node();
		newhead->data = val;
		newhead->next = head;
		newhead->prev = head->prev;
		head->prev = newhead;
		newhead->prev->next = newhead;
		head = newhead; //在初始化完newhead->next和newhead->prev后才可更新表头
	}
}

void bicirlinkedlist::del(int val) {
	if (head == NULL) return;
	else if (head->data == val) {
		node* del = head; //更新表头前先记录被删表头
		if (head->next == head) {
			delete del;
			head = NULL;
		}
		else {
			head = head->next;
			head->prev = del->prev;
			del->prev->next = head;
			delete del;
		}
	}
	else {
		node* prev = head, * del; //prev最终为val对应结点的前驱（被删元素不是表头，故一定存在前驱）
		while (prev->next != head && prev->next->data != val) {
			prev = prev->next;
		}
		if (prev->next == head) return; //prev已在表尾，仍未找到val，即表中没有val，无需删除
		del = prev->next; //更新prev->next前先记录所删结点
		prev->next = del->next;
		del->next->prev = prev;
		delete del;
	}
}

int bicirlinkedlist::getval(node* addr)
{
	return addr->data;
}

node* bicirlinkedlist::getprev(node* addr) {
	if (addr != NULL) return addr->prev;
	else return NULL;
}

node* bicirlinkedlist::getnext(node* addr)
{
	if (addr != NULL) return addr->next;
	else return NULL;
}

void bicirlinkedlist::traverse()
{
	if (head == NULL) return;
	printf("%d ", head->data);
	node* cur = head->next;
	while (cur != head) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}