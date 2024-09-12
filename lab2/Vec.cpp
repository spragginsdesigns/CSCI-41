#include "vec.h"
#include <algorithm>  // for std::sort
#include <stdexcept>  // for std::out_of_range

// Constructor
Vec::Vec() : arr(new int[1]), numItems(0), capacity(1) {}

// Destructor
Vec::~Vec() {
    delete[] arr;  // Free the dynamically allocated memory
}

// Copy Constructor (Deep Copy)
Vec::Vec(const Vec& other) : arr(new int[other.capacity]), numItems(other.numItems), capacity(other.capacity) {
    std::copy(other.arr, other.arr + numItems, arr);  // Deep copy the array
}

// Copy Assignment Operator (Deep Copy)
Vec& Vec::operator=(const Vec& other) noexcept {
    if (this != &other) {  // Check for self-assignment
        delete[] arr;  // Free existing memory
        capacity = other.capacity;
        numItems = other.numItems;
        arr = new int[capacity];
        std::copy(other.arr, other.arr + numItems, arr);  // Deep copy
    }
    return *this;
}

// Resize the array to double its current capacity
void Vec::resize() {
    capacity *= 2;
    int* newArr = new int[capacity];
    for (int i = 0; i < numItems; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

// Add an element to the vector
void Vec::push_back(int x) {
    if (numItems == capacity) {
        resize();
    }
    arr[numItems++] = x;
}

// Return the number of elements in the vector
int Vec::size() const {
    return numItems;
}

// Access element at index i, with bounds checking
int& Vec::at(int i) {
    if (i < 0 || i >= numItems) {
        throw std::out_of_range("Index out of range");
    }
    return arr[i];
}

// Sort the vector
void Vec::sort() {
    std::sort(arr, arr + numItems);
}
