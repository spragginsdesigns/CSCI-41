#include "list.h"

List::List() {
    // Initialize an empty list
    first = nullptr;
    last = nullptr;
}

const Node* List::getFirst() {
    return first;
}

const Node* List::getLast() {
    return last;
}

void List::push_front(Point2D data) {
    Node* newNode = new Node{data, first};
    first = newNode;
    if (last == nullptr) {
        // If the list was empty, the new node is also the last node
        last = newNode;
    }
}

void List::push_back(Point2D data) {
    Node* newNode = new Node{data, nullptr};
    if (last == nullptr) {
        // If the list was empty, the new node is both first and last
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

void List::pop_front() {
    if (first == nullptr) {
        return; // List is empty, nothing to pop
    }
    Node* temp = first;
    first = first->next;
    delete temp;
    if (first == nullptr) {
        // If the list becomes empty after popping, update last
        last = nullptr;
    }
}

void List::pop_back() {
    if (first == nullptr) {
        return; // List is empty, nothing to pop
    }
    if (first == last) {
        // Only one element in the list
        delete first;
        first = nullptr;
        last = nullptr;
    } else {
        Node* current = first;
        while (current->next != last) {
            current = current->next;
        }
        delete last;
        last = current;
        last->next = nullptr;
    }
}

int List::size() {
    int count = 0;
    Node* current = first;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

List::~List() {
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
    last = nullptr;
}

List& List::operator=(const List& other) {
    if (this != &other) {
        // Clear the current list
        this->~List();

        // Copy elements from other list
        Node* current = other.first;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }
    return *this;
}

List::List(const List& other) : first(nullptr), last(nullptr) {
    Node* current = other.first;
    while (current != nullptr) {
        push_back(current->data);
        current = current->next;
    }
}
