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

        std::size_t getSize() const;
        bool isEmpty() const;
        std::size_t indexOf(T item) const;
        bool contains(T item) const;
        const T& top() const;
        T& top();
        
        void push(T item);
        void pop(T item);
        void clear();

        LinkedList<T>::f_iterator begin() const;
        LinkedList<T>::f_iterator end() const;
};

#endif
