#ifndef __NODE_H__
#define __NODE_H__

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
                Node<T>* deleteAfetr();
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
void Node<T>::insertAfetr(Node<T>* p)
{
        p->next = next;
        next = p;
}

template <class T>
Node<T>* Node<T>::deleteAfter()
{
        if (next == 0)
        {
                return;
        }
        Node<T>* tmp = next;
        next = next->next;
        return tmp;
}
#endif
