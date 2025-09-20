
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Insertion methods
    void insertBegin(const T& value);
    void insertEnd(const T& value);
    void insertAtPosition(int position, const T& value);

    // Deletion methods
    void deleteBegin();
    void deleteEnd();
    void deleteAtPosition(int position);
    void deleteByValue(const T& value);

    // Sorting methods
    void quickSort();
    void mergeSort();

    // Helper functions
    void display() const; // Display the linked list content
};

#endif  
