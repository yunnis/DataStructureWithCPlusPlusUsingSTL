#ifndef D_NODEL_H_INCLUDED
#define D_NODEL_H_INCLUDED

#include <iostream>
#include <string>

#include "d_node.h"
#include "d_dnode.h"

using namespace std;

/// 输出单链表的每个元素，间隔为separate
template <typename T>
void writeLinkedList(node<T> *front, const string& separator);

/// 输出双链表的每个元素，间隔为separator
template <typename T>
void writeDLinkedList(dnode<T> *heard, const string& separator);

/// 在curr后插入一个值为item的新节点
template <typename T>
dnode<T> *insert(dnode<T> *curr, const T& item);

/// 在curr之后删除一个dnode
template <typename T>
void erase(dnode<T> *curr);

//
//  函数实现
//

template <typename T>
void writeLinkedList(node<T> *front, const string& separator)
{
	node<T> *curr;

	curr = front;
	while(curr != NULL)
	{
		cout << front->next->nodeValue << separator;
		curr = curr->next;
	}
}

template <typename T>
void writeDLinkedList(dnode<T> *header,const string& separator)
{
	dnode<T> *p = header->next;

	while(p != header)
	{
		cout << p->nodeValue << separator;
		p = p->next;
	}
}

template <typename T>
dnode<T> *insert(dnode<T> *curr, const T& item)
{
	dnode<T> *newNode, *prevNode;
	newNode = new dnode<T>(item);
	prevNode = curr->prev;

	newNode->next = curr;
	newNode->prev = prevNode;

	prevNode->next = newNode;
	curr->prev = newNode;

	return newNode;
}

template <typename T>
void erase(dnode<T> *curr)
{
	// 如果链表为空
	if(curr->next == curr)
		return;
	dnode<T> *prevNode = curr->prev, *succNode = curr->next;

	prevNode->next = succNode;
	succNode->prev = prevNode;

	delete curr;
}

#endif // D_NODEL_H_INCLUDED
