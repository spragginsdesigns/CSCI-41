#include "vec.h"
#include <algorithm>

Vec::Vec() {
    numItems = 0;
    capacity = 1;
    arr = new int[capacity];
}

void Vec::resize() {
    capacity *= 2;
    int* newArr = new int[capacity];

    for (int i = 0; i < numItems; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}

void Vec::push_back(int x) {
    if (numItems == capacity) {
        resize();
    }
    arr[numItems] = x;
    numItems++;
}

int Vec::size() const {
    return numItems;
}

int& Vec::at(int i) {
    return arr[i];
}

void Vec::sort() {
    std::sort(arr, arr + numItems);
}
