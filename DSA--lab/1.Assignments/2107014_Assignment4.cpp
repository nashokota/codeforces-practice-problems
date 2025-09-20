

#include "2107014_Assignment4.h"

#include <bits/stdc++.h>
using namespace std;

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
}

template <typename T>
void DoublyLinkedList<T>::insertBegin(const T &value)
{
    Node<T> *newNode = new Node<T>(value);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertAtPosition(int position, const T &value)
{
    if (position < 0)
    {
        cerr << "Invalid position. Position must be a non-negative integer." << endl;
        return;
    }

    Node<T> *newNode = new Node<T>(value);
    if (!head)
    {
        head = tail = newNode;
    }
    else if (position == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else
    {
        Node<T> *current = head;
        int currentPosition = 0;
        while (currentPosition < position - 1 && current->next)
        {
            current = current->next;
            currentPosition++;
        }

        if (currentPosition < position - 1)
        {
            cerr << "Invalid position. Position exceeds the length of the list." << endl;
            delete newNode; // Cleanup the allocated memory
            return;
        }

        // Insert the new node in the middle
        newNode->next = current->next;
        if (current->next)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertEnd(const T &value)
{
    Node<T> *newNode = new Node<T>(value);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteBegin()
{
    if (!head)
    {
        return;
    }

    Node<T> *temp = head;
    head = head->next;

    if (head)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr;
    }

    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::deleteEnd()
{
    if (!tail)
    {
        return;
    }

    Node<T> *temp = tail;
    tail = tail->prev;

    if (tail)
    {
        tail->next = nullptr;
    }
    else
    {
        head = nullptr;
    }

    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::deleteAtPosition(int position)
{
    if (position < 0)
    {
        cerr << "Invalid position. Position must be a non-negative integer." << endl;
        return;
    }

    if (!head)
    {
        cerr << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }

    if (position == 0)
    {
        deleteBegin();
        return;
    }

    Node<T> *current = head;
    int currentPosition = 0;
    while (currentPosition < position && current)
    {
        current = current->next;
        currentPosition++;
    }

    if (!current)
    {
        cerr << "Invalid position. Position exceeds the length of the list." << endl;
        return;
    }

    current->prev->next = current->next;
    if (current->next)
    {
        current->next->prev = current->prev;
    }

    delete current;
}

template <typename T>
void DoublyLinkedList<T>::deleteByValue(const T &value)
{
    Node<T> *current = head;

    while (current)
    {
        if (current->data == value)
        {
            if (current->prev)
            {
                current->prev->next = current->next;
            }
            else
            {
                head = current->next;
            }

            if (current->next)
            {
                current->next->prev = current->prev;
            }
            else
            {
                tail = current->prev;
            }

            delete current;
            return;
        }

        current = current->next;
    }

    cerr << "Value not found in the list." << endl;
}

template <typename T>
void DoublyLinkedList<T>::display() const
{
    Node<T> *current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
Node<T> *partition(Node<T> *low, Node<T> *high)
{
    T pivot = high->data;
    Node<T> *i = low->prev;

    for (Node<T> *j = low; j != high; j = j->next)
    {
        if (j->data <= pivot)
        {
            i = (i) ? i->next : low;
            std::swap(i->data, j->data);
        }
    }

    i = (i) ? i->next : low;
    std::swap(i->data, high->data);

    return i;
}

template <typename T>
void quickSortUtil(Node<T> *low, Node<T> *high)
{
    if (high != nullptr && low != high && low != high->next)
    {
        Node<T> *pivot = partition(low, high);

        quickSortUtil(low, pivot->prev);
        quickSortUtil(pivot->next, high);
    }
}

template <typename T>
void DoublyLinkedList<T>::quickSort()
{
    quickSortUtil(head, tail);
}

template <typename T>
Node<T> *merge(Node<T> *left, Node<T> *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    Node<T> *result = nullptr;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
        result->next->prev = result;
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
        result->next->prev = result;
    }

    return result;
}

template <typename T>
Node<T> *mergeSortUtil(Node<T> *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node<T> *middle = head;
    Node<T> *fast = head->next;

    while (fast && fast->next)
    {
        middle = middle->next;
        fast = fast->next->next;
    }

    Node<T> *left = head;
    Node<T> *right = middle->next;
    middle->next = nullptr;

    left = mergeSortUtil(left);
    right = mergeSortUtil(right);

    return merge(left, right);
}

template <typename T>
void DoublyLinkedList<T>::mergeSort()
{
    head = mergeSortUtil(head);
    Node<T> *current = head;

    while (current && current->next)
    {
        current = current->next;
    }
    tail = current;
}

int main()
{
    // creating an instance of class
    DoublyLinkedList<int> myList;

    cout << "created array" << endl;
    // creating linked list
    myList.insertEnd(11);
    myList.insertEnd(12);
    myList.insertEnd(13);
    myList.insertEnd(14);
    myList.insertEnd(15);
    myList.insertEnd(16);

    // displaying linked list
    myList.display();

    // application of various insertion methods
    cout << "after inserting at beginning" << endl;
    myList.insertBegin(33);
    myList.display();

    cout << "after inserting at end" << endl;
    myList.insertEnd(88);
    myList.display();

    cout << "after inserting at position" << endl;
    myList.insertAtPosition(1, 100);
    myList.display();

    // applications of various deletion methods
    cout << "after deleting beginning" << endl;
    myList.deleteBegin();
    myList.display();

    cout << "after deleting end" << endl;
    myList.deleteEnd();
    myList.display();

    cout << "after deleting by value" << endl;
    myList.deleteByValue(14);
    myList.display();

    cout << "after deleting at position" << endl;
    myList.deleteAtPosition(2);
    myList.display();

    // application of quicksort method
    cout << "after applying quicksort" << endl;
    myList.quickSort();
    myList.display();

    // application of mergesort method
    cout << "after applying mergesort" << endl;
    myList.mergeSort();
    myList.display();

    return 0;
}