#ifndef ARRAYLIST
#define ARRAYLIST

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
};

#endif
