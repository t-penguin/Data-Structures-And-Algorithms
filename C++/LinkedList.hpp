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

        void copy(const LinkedList<T>& other);
        void destroy();
    public:
        LinkedList();
        LinkedList(const LinkedList<T>& other);
        ~LinkedList();
};

#endif
