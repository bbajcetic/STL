#include "vector.h"
#include <iostream>
template <typename T>
vector<T>::vector() {}

/* Constructors */
template <typename T>
vector<T>::vector(int capacity) {}

/* Destructor */
template <typename T>
vector<T>::~vector() {}

/* Methods */
template <typename T>
void vector<T>::push_back(T item) {}

template <typename T>
void vector<T>::pop_back() {}

template <typename T>
void vector<T>::clear() {}

template <typename T>
void vector<T>::print() const {}

/* Operators */
template <typename T>
T& vector<T>::operator[](std::size_t idx) const {
    return arr[idx];
}
