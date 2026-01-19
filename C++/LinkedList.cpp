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

// Returns the size of the list
template <typename T>
int LinkedList<T>::getSize() const {
    return size;
}

// Returns whether or not the list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

// Returns the index of the item in the list if found
// Returns -1 if not found
template <typename T>
int LinkedList<T>::indexOf(T item) const {
    int index = 0;
    Node<T>* curNode = first;

    while (curNode != nullptr) {
        if (curNode->info == item)
            return index;
        
        index++;
        curNode++;
    }

    return -1;
}

// Returns whether or not the item is in the list
template <typename T>
bool LinkedList<T>::contains(T item) const {
    return indexOf(item) != -1;
}

// Returns a const reference to the first item in the list
// Throws an out of range error if the list is empty
template <typename T>
const T& LinkedList<T>::front() const {
    if (isEmpty())
        throw std::out_of_range("Cannot get front of empty list");

    return first->info;
}

// Returns a const reference to the first item in the list
// Throws an out of range error if the list is empty
template <typename T>
const T& LinkedList<T>::back() const {
    if (isEmpty())
        throw std::out_of_range("Cannot get back of empty list");
    
    return last->info;
}

// Returns a non-const reference to the first item in the list
// Throws an out of range error if the list is empty
template <typename T>
T& LinkedList<T>::front() {
    return const_cast<T&>(*this).front();
}

// Returns a non-const reference to the first item in the list
// Throws an out of range error if the list is empty
template <typename T>
T& LinkedList<T>::back() {
    return const_cast<T&>(*this).back();
}

// Inserts the given item at the end of the list
template <typename T>
void LinkedList<T>::insert(T item) {
    Node<T>* newNode = new Node<T>(item);
    // Case 1: List has no nodes
    if (isEmpty()) {
        first = newNode;
        last = newNode;
        return;
    }

    // Case 2: List has at least one node
    last->next = newNode;
    last++;
}

// Inserts the given item at the specified index
// Performs a bounds check
template <typename T>
void LinkedList<T>::insertAt(T item, int index) {
    if (index < 0 || index > size)
        throw std::out_of_range("Index out of bounds");
    
    // Case 1: Inserting at the end of the list
    if (isEmpty() || index == size) {
        insert(item);
        return;
    }
    
    Node<T>* newNode = new Node<T>(item);
    // Case 2: Inserting at the front of the list
    if (index == 0) {
        newNode->next = first;
        first = newNode;
        return;
    }

    // Case 3: Inserting somewhere in the middle of the list
    Node<T>* curNode = (*this)[index - 1];
    newNode->next = curNode->next;
    curNode->next = newNode;
}

// Removes the first instance of the specified item
template <typename T>
void LinkedList<T>::remove(T item) {
    // Case 1: List has no nodes
    if (isEmpty())
        return;
    
    // Case 2: Removing the first node
    if (first->info == item) {
        removeFirst();
        return;
    }
        
    // Search for first node with matching info
    Node<T>* prevNode = first;
    Node<T>* curNode = prevNode->next;
    while (curNode != nullptr && curNode->info != item) {
        prevNode++;
        curNode++;
    }
    
    // Case 3: Item is not in list
    if (curNode == nullptr)
        return;

    // Case 4: Removing node somewhere in the middle of the list
    prevNode->next = curNode->next;
    delete curNode;

    // Case 5: Case 4 removed last node
    if (prevNode->next == nullptr)
        last = prevNode;
    
    size--;
}

// Removes the item at the specified index
// Performs a bounds check
template <typename T>
void LinkedList<T>::removeAt(int index) {
    if (index < 0 || index > size)
        throw std::out_of_range("Index out of bounds");
    
    // Case 1: Removing the first node
    if (index == 0) {
        removeFirst();
        return;
    }

    // Case 2: Removing the last node
    if (index == size - 1) {
        removeLast();
        return;
    }
    
    // Case 3: Removing node somewhere in the middle of the list
    Node<T>* prevNode = (*this)[index - 1];
    Node<T>* temp = prevNode->next;
    prevNode->next = temp->next;
    delete temp;
    size--;
}

// Removes the first node in the list
template <typename T>
void LinkedList<T>::removeFirst() {
    Node<T>* temp = first;
    first++;
    delete temp;
    size--;
}

// Removes the last node in the list
template <typename T>
void LinkedList<T>::removeLast() {
    delete last;
    last = (*this)[size - 1];
    last->next = nullptr;
    size--;
}

// Clears the entire list
template <typename T>
void LinkedList<T>::clear() {
    destroy();
}
