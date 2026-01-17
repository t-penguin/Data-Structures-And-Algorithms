#ifndef ARRAYLIST
#define ARRAYLIST

#include <iterator>

template <typename T>
class ArrayList {
    private:
        T* list;
        int count;
        int capacity;

        void copy(const ArrayList<T>& other);
        void destroy();
        void resize(int newCapacity);
    public:
        ArrayList(const int& size = 10);
        ArrayList(const ArrayList<T>& other);
        ~ArrayList();

        const ArrayList<T>& operator=(const ArrayList<T>& other);
        const T& operator[](int index) const;
        T& operator[](int index);

        int getCapacity() const;
        int getCount() const;
        bool isEmpty() const;
        bool isFull() const;
        int indexOf(T item) const;
        const T& front() const;
        const T& back() const;
        T& front();
        T& back(); 

        void insert(T item);
        void insertAt(T item, int index);
        void remove(T item);
        void removeAt(int index);
        void removeLast();
        void clear();

        void shrinkToFit();

        class f_iterator
        {
            private:
                ArrayList<T>& listRef;
                int index;
            public:
                using value_type = T;   // Type that this iterator points to
                using difference_type = std::ptrdiff_t; // Type used for finding difference between iterators
                using pointer = T*;     // Pointer to value_type
                using reference = T&;   // Reference to value_type
                using iterator_category = std::forward_iterator_tag;

                // Constructor performs bounds check
                // listRef.getCount() is a valid index to represent end state
                f_iterator(ArrayList<T>& list, const int pos) : listRef(list), index(pos) {
                    if (index < 0 || index > listRef.getCount())
                        throw std::out_of_range("Index out of bounds");
                }

                // Dereference operator
                // ArrayList access already performs bounds check
                reference operator*() const { return listRef[index]; }

                f_iterator& operator++() {
                    index++;
                    return *this;
                }

                bool operator==(const f_iterator& other) const {
                    return listRef == other.listRef && index == other.index;
                }

                bool operator!=(const f_iterator& other) const {
                    return listRef != other.listRef || index != other.index;
                }
        };

        class r_iterator
        {
            private:
                ArrayList<T>& listRef;
                int index;
            public:
                using value_type = T;   // Type that this iterator points to
                using difference_type = std::ptrdiff_t; // Type used for finding difference between iterators
                using pointer = T*;     // Pointer to value_type
                using reference = T&;   // Reference to value_type
                using iterator_category = std::forward_iterator_tag;

                // Constructor performs bounds check
                // -1 is a valid index to represent end state
                f_iterator(ArrayList<T>& list, const int pos) : listRef(list), index(pos) {
                    if (index < -1 || index >= listRef.getCount())
                        throw std::out_of_range("Index out of bounds");
                }

                // Dereference operator
                // ArrayList access already performs bounds check
                reference operator*() const { return listRef[index]; }

                f_iterator& operator++() {
                    index--;
                    return *this;
                }

                bool operator==(const f_iterator& other) const {
                    return listRef == other.listRef && index == other.index;
                }

                bool operator!=(const f_iterator& other) const {
                    return listRef != other.listRef || index != other.index;
                }
        };

        f_iterator begin() const;
        f_iterator end() const;

        r_iterator rbegin() const;
        r_iterator rend() const;
};

#endif
