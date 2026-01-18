#ifndef LINKEDLIST
#define LINKEDLIST

#include <iterator>

template <typename T>
struct Node {
    T info;
    Node<T>* next;

    Node(T item) : info(item), next(nullptr) {}
};

template <typename T>
class LinkedList {
    private:
        int size;
        Node<T>* first;
    public:
};

#endif
