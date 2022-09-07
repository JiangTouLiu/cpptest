#pragma once
#include <iostream>
using namespace std;



template <class T>
class Node
{
public:
	T data;
	Node();
	Node(const T& item, Node<T>* n);
	void insertAfter(Node<T>* p);
	Node <T>* deleteAfter();
	Node <T>* nextNode();
	Node <T>* next;

};

template <class T>
Node<T>::Node(const T& item, Node<T>* n) :data(item), next(n)
{

}

template <class T>
void Node <T>::insertAfter(Node <T>* p)
{
	p->next = next;
	next = p;

}

template <class T>
Node <T>* Node <T>::deleteAfter()
{
	Node<T>* tem = next;
	if (next == 0)
	{
		return 0;
	}
	next = tem->next;
	return tem;
}

template <class T>
Node<T>* Node <T>::nextNode()
{
	return next;
}









template <class T>
class LinkList
{
public:
	LinkList();
	LinkList(LinkList& l);
	LinkList<T>& operator =(LinkList<T>& l);
	int getSize() const;
	bool isEmpty() const;
	void reset(int pos = 0);
	void next();	//使游标移动到下一个节点
	bool endOfList() const;	//判断游标是不是到了链尾
	int currentPos() const;	//返回游标当前位置
	void insertFront(const T& item);	//表头插入节点
	void insertRear(const T& item);		//表尾插入节点
	void insertAt(const T& item);		//当前节点之前插入
	void insertAfter(const T& item);	//当前节点之后插入
	T deleteFront();	//删除头节点
	void deleteCurrent();	//删除当前节点
	T& data();		//返回对当前节点的数据的引用
	void clear();	//清空链表
	Node<T>* newNode(const T& item, Node<T>* n);
private:
	Node<T>* front;
	Node<T>* rear;
	Node<T>* pre;
	Node<T>* cur;
	int size;
	int position;
	
	void freeNode(Node<T>* p);
	void copy(LinkList<T>& l);
};

template <class T>
LinkList<T>::LinkList()
{
	front = NULL;
	rear = NULL;
	pre = NULL;
	cur = NULL;
	size = 0;
	position = 0;
}

template <class T>
Node<T>* LinkList<T>::newNode(const T& item, Node<T>* n)
{
	Node<T>* np = new Node<T>(item, n);
	return np;
}

template <class T>
void freeNode(Node<T>* p)
{
	delete p;
}

template <class T>
void LinkList<T>::insertFront(const T& item)
{
	if (0 == size)
	{
		front = newNode(item, NULL);
		rear = front;
		pre = front;
		cur = front;
	}
	else
	{
		front = newNode(item, front);
	}
	++size;
}

template <class T>
void LinkList<T>::insertRear(const T& item)
{
	if (0 == size)
	{
		rear = insertFront(item);
	}
	else
	{
		rear.next = newNode(item, NULL);
		rear = rear.next;
	}

	++size;
}

template <class T>
void LinkList<T>::insertAt(const T& item)
{
	if (0 == size)
	{
		cout << "there is nothing " << endl;
	}
	else if (0 == position)
	{
		insertFront(item);
	}
	else if (size > position)
	{
		pre->next = newNode(item, cur);
	}
	++size;
}

template <class T>
void LinkList<T>::insertAfter(const T& item)
{
	if (0 == size)
	{
		cout << "链表为空，无法插入" << endl;
	}
	else if (size > position)
	{
		cur->next = newNode(item, cur->nextNode());
	}
	++size;
}

template <class T>
T& LinkList<T>::data()
{
	return cur->data;
}

template <class T>
void LinkList<T>::next()
{
	cur = cur->next;
	pre = pre->next;
}

template <class T>
int LinkList<T>::getSize() const
{
	return size;
}
