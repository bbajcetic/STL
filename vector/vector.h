// vector.h
#ifndef VECTOR_H
#define VECTOR_H
template <typename T>
class vector {
private:
    static const int DEFAULT_SIZE = 10;
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
    int capacity() { return capacity_; }
    int size() { return size_; }
};
#include "vector.cpp"
#endif

