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


