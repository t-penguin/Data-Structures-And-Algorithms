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
