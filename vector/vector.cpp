#include "vector.h"
#include <iostream>

/* Constructors */
template <typename T>
vector<T>::vector(): size_(0), capacity_(DEFAULT_CAPACITY) {
    arr = new T[capacity_];
}

template <typename T>
vector<T>::vector(int capacity): size_(0), capacity_(capacity) {
    arr = new T[capacity_];
}


/* Destructor */
template <typename T>
vector<T>::~vector() {}


/* Methods */
template <typename T>
void vector<T>::push_back(T item) {
    if (size_ == capacity_) {
        capacity_ *= 2;
        T* newArr = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    arr[size_++] = item;
}

template <typename T>
void vector<T>::pop_back() {
    if (size_ == 0 || capacity_ == 0) { return; }
    size_--;
}

template <typename T>
void vector<T>::clear() {
    delete[] arr;
    size_ = 0;
    capacity_ = DEFAULT_CAPACITY;
    arr = new T[capacity_];
}

template <typename T>
void vector<T>::print() const {}


/* Operators */
template <typename T>
T& vector<T>::operator[](std::size_t idx) const {
    return arr[idx];
}
