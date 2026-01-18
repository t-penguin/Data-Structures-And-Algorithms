#ifndef LINKEDLIST
#define LINKEDLIST

#include <iterator>

template <typename T>
struct Node {
    T info;
    Node<T>* next;

    Node(T item) : info(item), next(nullptr) {}
    
    Node<T>& operator++() { 
        this = this->next;
        return *this;
    }

    Node<T>& operator++(int) {
        Node<T> temp(*this);
        this = this->next;
        return temp;
    }
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

        const LinkedList<T>& operator=(const LinkedList<T>& other);
        const T& operator[](int index) const;
        T& operator[](int index);
};

#endif
