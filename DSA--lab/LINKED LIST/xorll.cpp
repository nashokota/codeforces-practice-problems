#include <iostream>

using namespace std;

// Definition of a node in the XOR linked list
struct Node {
    int data;
    Node* xorPtr; // XOR of previous and next pointers
};

// Function to perform XOR operation on pointers
Node* xorPtr(Node* a, Node* b) {
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
}

// Function to traverse the XOR linked list in forward direction
void traverseForward(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next;

    cout << "Forward traversal:" << endl;
    while (current != nullptr) {
        cout << current->data << " ";

        // Move to the next node
        next = xorPtr(prev, current->xorPtr);
        prev = current;
        current = next;
    }
    cout << endl;
}

int main() {
    // Example usage
    Node* head = new Node{1, nullptr}; // Head node
    Node* second = new Node{2, nullptr}; // Second node
    head->xorPtr = xorPtr(nullptr, second); // Head's xorPtr is XOR of nullptr and second
    second->xorPtr = xorPtr(head, nullptr); // Second node's xorPtr is XOR of head and nullptr

    // Traversing the XOR linked list
    traverseForward(head);

    // Clean up memory
    delete head;
    delete second;

    return 0;
}
