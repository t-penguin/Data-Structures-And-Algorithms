#include <LinkedList.hpp>
#include <stdexcept>

// Constructor
template <typename T>
LinkedList<T>::LinkedList() {
    size = 0;
    first = nullptr;
    last = nullptr;
}

// Copy Constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    copy(other);
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    destroy();
}

// Copy helper function
template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& other) {
    if (this == &other)
        return;
    
    size = other.size;
    if (other.first == nullptr)
        return;
    
    // Copy first node
    Node<T>* otherNode = other.first;
    first = new Node<T>(otherNode->info);

    // Iterate through list, copying nodes
    Node<T>* curNode = first;
    otherNode++;
    while (otherNode != nullptr) {
        curNode->next = new Node<T>(otherNode->info);
        otherNode++;
    }
    
    last = curNode;
    curNode->next = nullptr;
}

// Destroy helper function
template <typename T>
void LinkedList<T>::destroy() {
    size = 0;
    Node<T>* curNode;
    while (first != nullptr) {
        curNode = first;
        first++;
        delete curNode;
    }

    first = nullptr;
    last = nullptr;
}

// Overloaded assignment operator
template <typename T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this != &other)
        destroy();
    
    copy(other);
    return *this;
}

// Overloaded const access operator
template <typename T>
const T& LinkedList<T>::operator[](int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of bounds");

    if (index == size - 1)
        return last->info;
    
    Node<T>* curNode = first;
    while (index > 0) {
        curNode++;
        index--;
    }
    
    return curNode->info;
}

// Overloaded non-const access operator
template <typename T>
T& LinkedList<T>::operator[](int index) {
    return const_cast<T&>(*this).operator[](index);
}
