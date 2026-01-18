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
