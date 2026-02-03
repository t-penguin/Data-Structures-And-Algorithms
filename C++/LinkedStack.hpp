#ifndef LINKEDSTACK
#define LINKEDSTACK

#include "LinkedList.hpp"

template <typename T>
class LinkedStack : protected LinkedList
{
    public:
        LinkedStack();
        LinkedStack(const LinkedStack<T>& other);
        ~LinkedStack();

        const LinkedStack<T>& operator=(const LinkedStack<T>& other);

        int getSize() const;
        bool isEmpty() const;
        int indexOf(T item) const;
        bool contains(T item) const;
        const T& top() const;
        T& top();
        
        void push(T item);
        void pop(T item);
        void clear();
};

#endif
