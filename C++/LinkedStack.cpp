#include "LinkedStack.hpp"
#include <stdexcept>

// Constructor
template <typename T>
LinkedStack<T>::LinkedStack() : LinkedList<T>() { }

// Copy Constructor
template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T> &other) : LinkedList<T>(other) { }

// Destructor
template <typename T>
LinkedStack<T>::~LinkedStack() { }

// Overloaded Assignment Operator
template <typename T>
const LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T> &other) { 
    if (this != &other)
        LinkedList<T>::operator=(other);
    
    return *this;
}

// Returns the size of the stack
template <typename T>
std::size_t LinkedStack<T>::getSize() const {
    return LinkedList<T>::getSize();
}

// Returns whether or not the stack is empty
template <typename T>
bool LinkedStack<T>::isEmpty() const {
    return LinkedList<T>::isEmpty();
}

// Returns the index of the first occurance of an item in the stack if found
// Returns -1 if not found
template <typename T>
std::size_t LinkedStack<T>::indexOf(T item) const {
    return LinkedList<T>::indexOf(item);
}

// Returns whether or not the item is in the stack
template <typename T>
bool LinkedStack<T>::contains(T item) const {
    return LinkedList<T>::contains(item);
}

// Returns a const reference to the top item of the stack
// Throws an out of range error if the stack is empty
template <typename T>
const T& LinkedStack<T>::top() const {
    return LinkedList<T>::front();
}

// Returns a non-const reference to the top item of the stack
// Throws an out of range error if the stack is empty
template <typename T>
T& LinkedStack<T>::top() {
    return const_cast<T&>(*this).top();
}

// Inserts an item at the top of the stack
template <typename T>
void LinkedStack<T>::push(T item) {
    LinkedList<T>::insertAt(item, 0);
}

// Removes the top item of the stack
template <typename T>
void LinkedStack<T>::pop(T item) {
    LinkedList<T>::removeFirst();
}

// Clears the stack
template <typename T>
void LinkedStack<T>::clear() {
    LinkedList<T>::clear();
}

// Returns an iterator pointing to the top of the stack
template <typename T>
LinkedList<T>::f_iterator LinkedStack<T>::begin() const {
    return LinkedList<T>::begin();
}

// Returns an iterator representing one after the end of the list
template <typename T>
LinkedList<T>::f_iterator LinkedStack<T>::end() const {
    return LinkedList<T>::end();
}
