#include <LinkedList.hpp>
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList() {
    size = 0;
    first = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    copy(other);
}

template <typename T>
LinkedList<T>::~LinkedList() {
    destroy();
}
