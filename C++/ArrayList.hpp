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
    public:
        ArrayList(const int& size = 10);
        ArrayList(const ArrayList<T>& other);
        ~ArrayList();

        const ArrayList<T>& operator=(const ArrayList<T>& other);

        int getCapacity();
        int getCount();
        bool isEmpty();
        bool isFull();
        int indexOf(T item);

        void insert(T item);
        void insertAt(T item, int index);
        void remove(T item);
        void removeAt(int index);
};

#endif
