#include <ArrayList.hpp>
#include <stdexcept>

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

// Overloaded const Access Operator
template <typename T>
const T& ArrayList<T>::operator[](int index) const {
    if (index < 0 || index >= count)
        throw std::out_of_range("Index out of bounds");
    
    return list[index];
}

// Overloaded non-const Access Operator
template <typename T>
T& ArrayList<T>::operator[](int index) {
    return const_cast<T&>(*this).operator[](index);
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

// Resizes the underlying array to 1.5x capacity
// Allocates new memory for the new array
template <typename T>
void ArrayList<T>::resize(int newCapacity) {
    T* newList = new T[newCapacity];
    for (int i = 0; i < count; i++)
        newList[i] = list[i];
    
    delete[] list;
    list = newList;
}

// Returns the capacity of the list
template <typename T>
int ArrayList<T>::getCapacity() const {
    return capacity;
}

// Returns the count of items in the list
template <typename T>
int ArrayList<T>::getCount() const {
    return count;
}

// Returns whether or not the list is empty
template <typename T>
bool ArrayList<T>::isEmpty() const {
    return count == 0;
}

// Returns whether or not the list is full
template <typename T>
bool ArrayList<T>::isFull() const {
    return count == capacity;
}

// Performs a linear search to find an item in the list
// Returns the index of the item if found
// Returns -1 otherwise
template <typename T>
int ArrayList<T>::indexOf(T item) const {
    for (int i = 0; i < count; i++)
        if (list[i] == item)
            return i;
    
    return -1;
}

// Returns a const reference to the first item in the list
// Throws an out of range error if the list is empty
template <typename T>
const T& ArrayList<T>::front() const {
    if (isEmpty())
        throw std::out_of_range("Cannot get front of empty list");
    
    return list[0];
}

// Returns a const reference to the last item in the list
// Throws an out of range error if the list is empty
template <typename T>
const T& ArrayList<T>::back() const {
    if (isEmpty())
        throw std::out_of_range("Cannot get back of empty list");
    
    return list[count - 1];
}

// Returns a reference to the first item in the list
// Throws an out of range error if the list is empty
template <typename T>
T& ArrayList<T>::front() {
    return const_cast<T&>(*this).front();
}

// Returns a reference to the first item in the list
// Throws an out of range error if the list is empty
template <typename T>
T& ArrayList<T>::back() {
    return const_cast<T&>(*this).back();
}

// Inserts an item at the end of the list
// Increases the capacity if the list is full
template <typename T>
void ArrayList<T>::insert(T item) {
    if (isFull())
        resize(capacity * 1.5);

    list[++count] = item;
}

// Inserts an item at given index
// Increases the capacity if the list is full
// Shifts the rest of the list up by 1
template <typename T>
void ArrayList<T>::insertAt(T item, int index) {
    if (index < 0 || index >= count)
        throw std::out_of_range("Index out of bounds");
    
    if (isFull())
        resize(capacity * 1.5);

    for (int i = count; i > index; i--)
        list[i] = list[i - 1];
    
    list[index] = item;
    count++;
}

// Removes the first instance of an item in a list
// Shifts the rest of the list down
template <typename T>
void ArrayList<T>::remove(T item) {
    int index = indexOf(item);
    if (index < 0)
        return;
    
    removeAt(index);
}

// Removes the item at the specified index
// Shifts the rest of the list down
template <typename T>
void ArrayList<T>::removeAt(int index) {
    if (index < 0 || index >= count)
        throw std::out_of_range("Index out of bounds");
    
    count--;
    for (int i = index; i < count; i++)
        list[i] = list[i + 1];
}

// Removes the item at the end of the list
template <typename T>
void ArrayList<T>::removeLast() {
    if (isEmpty())
        return;
    
    count--;
}

// Clears the list
template <typename T>
void ArrayList<T>::clear() {
    count = 0;
}

// Resizes the list to match the capacity to its count
template <typename T>
void ArrayList<T>::shrinkToFit() {
    resize(count);
}

// Returns a forward iterator pointing to the beginning of the list
template <typename T>
typename ArrayList<T>::f_iterator ArrayList<T>::begin() const {
    return f_iterator(*this, 0);
}

// Returns a forward iterator pointing to the end of the list
template <typename T>
typename ArrayList<T>::f_iterator ArrayList<T>::end() const {
    return f_iterator(*this, count);
}

// Returns a reverse iterator pointing to the beginning of the list
template <typename T>
typename ArrayList<T>::r_iterator ArrayList<T>::rbegin() const {
    return f_iterator(*this, count - 1);
}

// Returns a reverse iterator pointing to the end of the list
template <typename T>
typename ArrayList<T>::r_iterator ArrayList<T>::rend() const {
    return f_iterator(*this, -1);
}