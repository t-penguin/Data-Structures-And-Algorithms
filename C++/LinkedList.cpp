#include <LinkedList.hpp>
#include <stdexcept>

// Constructor
template <typename T>
LinkedList<T>::LinkedList() {
    size = 0;
    first = nullptr;
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
    otherNode = otherNode->next;
    while (otherNode != nullptr)
        curNode->next = new Node<T>(otherNode->info);
    
    curNode->next = nullptr;
}

// Destroy helper function
template <typename T>
void LinkedList<T>::destroy() {
    size = 0;
    Node<T>* curNode;
    while (first != nullptr) {
        curNode = first;
        first = first->next;
        delete curNode;
    }
}
