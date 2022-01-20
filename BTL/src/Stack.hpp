#include "Node.hpp"

template <class T>
class Stack
{
private:
    Node<T> *pTop; // con trỏ để quản lí stack
    int size;

public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(const T &value);
    void pop();
    T top();
    int sizeOf();
};

template <class T>
Stack<T>::Stack()
    : pTop(NULL), size(0) {}

template <class T>
Stack<T>::~Stack()
{
    Node<T> *t = NULL;
    while (pTop != NULL)
    {
        t = pTop;
        pTop = pTop->pNext;
        delete t;
    }
    size = 0;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (pTop == NULL)
        return 1;
    return 0;
}

template <class T>
void Stack<T>::push(const T &value)
{
    Node<T> *p = new Node(value);
    if (p == NULL)
    {
        cout << "\n\t\t(!) Not enough memory to allocation (!)" << endl;
        return;
    }
    else
    {
        if (isEmpty())
        {
            pTop = p;
        }
        else
        {
            p->pNext = pTop;
            pTop = p;
        }
        size++;
    }
}

template <class T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        Node<T> *t = pTop;
        pTop = pTop->pNext; // cập nhật lại Node đầu là thằng dưới
        delete t;
        size--;
    }
}

template <class T>
T Stack<T>::top()
{
    return pTop->data;
}

template <class T>
int Stack<T>::sizeOf()
{
    return this->size;
}
