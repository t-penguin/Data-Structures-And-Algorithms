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
        Node<T>* last;

        void copy(const LinkedList<T>& other);
        void destroy();
    public:
        LinkedList();
        LinkedList(const LinkedList<T>& other);
        ~LinkedList();

        const LinkedList<T>& operator=(const LinkedList<T>& other);
        const T& operator[](int index) const;
        T& operator[](int index);

        int getSize() const;
        bool isEmpty() const;
        int indexOf(T item) const;
        bool contains(T item) const;
        const T& front() const;
        const T& back() const;
        T& front();
        T& back();
        
        void insert(T item);
        void insertAt(T item, int index);
        void remove(T item);
        void removeAt(int index);
        void removeFirst();
        void removeLast();
        void clear();
};

#endif
