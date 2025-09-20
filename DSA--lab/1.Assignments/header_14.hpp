
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Deque {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Deque();
    ~Deque();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    bool empty() const;
    void display() const;
    int size() const;
};

template <typename T>
Deque<T>::Deque() : front(nullptr), rear(nullptr) {}

template <typename T>
Deque<T>::~Deque() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void Deque<T>::push_front(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (empty()) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

template <typename T>
void Deque<T>::push_back(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (empty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

template <typename T>
void Deque<T>::pop_front() {
    if (!empty()) {
        Node<T>* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
    }
}

template <typename T>
void Deque<T>::pop_back() {
    if (!empty()) {
        Node<T>* temp = rear;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
    }
}

template <typename T>
bool Deque<T>::empty() const {
    return front == nullptr;
}

template <typename T>
void Deque<T>::display() const {
    Node<T>* current = front;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
int Deque<T>::size() const {
    int count = 0;
    Node<T>* current = front;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

template <typename T>
class Queue : public Deque<T> {
public:
    Queue();
    ~Queue();

    void push(const T& value);
    void pop();
};

template <typename T>
Queue<T>::Queue() {}

template <typename T>
Queue<T>::~Queue() {}

template <typename T>
void Queue<T>::push(const T& value) {
    this->push_back(value);
}

template <typename T>
void Queue<T>::pop() {
    this->pop_front();
}

template <typename T>
class Stack : public Deque<T> {
public:
    Stack();
    ~Stack();

    void push(const T& value);
    void pop();
};

template <typename T>
Stack<T>::Stack() {}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
void Stack<T>::push(const T& value) {
    this->push_front(value);
}

template <typename T>
void Stack<T>::pop() {
    this->pop_front();
}

#endif
