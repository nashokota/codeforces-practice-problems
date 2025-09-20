#include <iostream>

using namespace std;

// Definition of a node in the circular linked list
struct Node {
    int data;
    Node* next;
};

// Function to find the end node of the circular linked list
Node* findEnd(Node* head) {
    if (head == nullptr)
        return nullptr;

    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    return current;
}

int main() {
    // Example usage
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = head; // Circular reference

    Node* endNode = findEnd(head);
    if (endNode != nullptr)
        cout << "End node data: " << endNode->data << endl;
    else
        cout << "List is empty!" << endl;

    // Clean up memory
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
