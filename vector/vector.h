// vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>

class vectorBase {
public:
    static const int DEFAULT_CAPACITY;
};
const int vectorBase::DEFAULT_CAPACITY = 10;

template <typename T>
class vector: public vectorBase {
private:
    int size_;
    int capacity_;
public:
    T* arr;

    /* Constructors */
    vector();
    vector(int capacity);
    void init(int capacity);

    /* Destructor */
    ~vector();

    /* Methods */
    void push_back(T item);
    void pop_back();
    void clear();
    void print() const;

    /* Getters */
    int capacity() const { return capacity_; }
    int size() const { return size_; }
    bool empty() const { return size_ == 0; }

    /* Operators */
    T& operator[](std::size_t idx) const;
};
#include "vector.cpp"
#endif

