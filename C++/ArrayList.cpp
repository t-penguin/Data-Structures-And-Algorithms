#include <ArrayList.hpp>

// Constructor
template <typename T>
ArrayList<T>::ArrayList(const int& size) {
    count = 0;
    capacity = size;
    list = new T[capacity];
}

// Copy Constructor
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other) {
    copy(other);
}

// Destructor
template <typename T>
ArrayList<T>::~ArrayList() {
    destroy();
}

// Overloaded Assignment Operator
template <typename T>
const ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    
    return *this;
}

// Copy Helper Function
template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& other) {
    count = other.count;
    capacity = other.capacity;
    list = new T[capacity];
    for (int i = 0; i < count; i++)
        list[i] = other.list[i];
}

// Destory Helper Function
template <typename T>
void ArrayList<T>::destroy() {
    delete[] list;
}

// Returns the capacity of the list
template <typename T>
int ArrayList<T>::getCapacity() {
    return capacity;
}

// Returns the count of items in the list
template <typename T>
int ArrayList<T>::getCount() {
    return count;
}

// Returns whether or not the list is empty
template <typename T>
bool ArrayList<T>::isEmpty() {
    return count == 0;
}

// Returns whether or not the list is full
template <typename T>
bool ArrayList<T>::isFull() {
    return count == capacity;
}

// Performs a linear search to find an item in the list
// Returns the index of the item if found
// Returns -1 otherwise
template <typename T>
int ArrayList<T>::indexOf(T item) {
    for (int i = 0; i < count; i++)
        if (list[i] == item)
            return i;
    
    return -1;
}
