#include <iostream>
using namespace std;

template <class T>
class Node
{
        public:
                T data;
                Node(Node<T>* n, const T& t);
                T& getData();
                Node<T>* nextNode();
                Node<T>* nextNode() const;
                void insertAfter(Node<T>* p);
                Node<T>* deleteAfter();
        private:
                Node<T>* next;
};

template <class T>
Node<T>::Node(Node<T>* n, const T& t):next(n),data(t)
{}

template <class T>
T& Node<T>::getData()
{
        return data;
}

template <class T>
Node<T>* Node<T>::nextNode()
{
        return next;
}


template <class T>
Node<T>* Node<T>::nextNode() const
{
        return next;
}

template <class T>
void Node<T>::insertAfter(Node<T>* p)
{
        p->next = next;
        next = p;
}

template <class T>
Node<T>* Node<T>::deleteAfter()
{
        if (next == 0)
        {
                return NULL;
        }
        Node<T>* tmp = next;
        next = next->next;
        return tmp;
}

template <class T>
class Link
{
        public:
                Link():head(NULL),rear(NULL),prev(NULL),curr(NULL){};
                Link(const Node<T>* h):head(h),rear(h),prev(h),curr(h){};
                void insertAtHead(Node<T>* n);
                void insertAtRear(Node<T>* n);
                void insertAtCurr(Node<T>* n);
                void insertAfterCurr(Node<T>* n);
                Node<T>* remove(Node<T>* n);
                int search();
                Node<T>* getHead();
        private:
                Node<T>* head;
                Node<T>* rear;
                Node<T>* prev;
                Node<T>* curr;
                int count;
};

template <class T>
void Link<T>::insertAtHead(Node<T>* n)
{
        head->Node<T>::insertAfter(n);
        count++;
}

template <class T>
void Link<T>::insertAtRear(Node<T>* n)
{
        rear->Node<T>::inserAfter(n);
        count++;
}

template <class T>
void Link<T>::insertAtCurr(Node<T>* n)
{
        curr->Node<T>::inserAfter(n);
        count++;
}

template <class T>
void Link<T>::insertAfterCurr(Node<T>* n)
{
        prev->Node<T>::inserAfter(n);
        count++;
}

template <class T>
Node<T>* Link<T>::remove(Node<T>* n)
{
        return prev->Node<T>::deleteAfter();
}

template <class T>
Node<T>* Link<T>::getHead()
{
        return head;
}
int main()
{
        Node<int> n1(NULL, 10);
        Node<int> n2(NULL, 20);
        Node<int> n3(NULL, 30);
        Link<int> l;
        l.insertAtHead(&n1);
        l.insertAtHead(&n2);
        l.insertAtHead(&n3);
        cout << l.getHead()->getData() << endl;
        cout << l.getHead()->nextNode()->getData() << endl;
        cout << l.getHead()->nextNode()->nextNode()->getData() << endl;
        return 0;
}
