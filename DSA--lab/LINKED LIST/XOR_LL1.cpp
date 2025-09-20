#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* npx;  // XOR of next and previous node

    Node(int data) {
        this->data = data;
        this->npx = nullptr;
    }
};

Node* XOR(Node* a, Node* b) {
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
}

Node* convertarr2ll(vector<int> &arr) {
    Node* head = nullptr;
    for(int i = arr.size() - 1; i >= 0; --i) {
        Node* newNode = new Node(arr[i]);
        newNode->npx = XOR(nullptr, head);
        if (head != nullptr) {
            Node* next = XOR(nullptr, head->npx);
            head->npx = XOR(newNode, next);
        }
        head = newNode;
    }
    return head;
}

Node* insertAtHead(int data, Node* head) {
    Node* newNode = new Node(data);
    newNode->npx = XOR(nullptr, head);

    if (head != nullptr) {
        Node* next = XOR(nullptr, head->npx);
        head->npx = XOR(newNode, next);
        if (next != nullptr) {
            // Get the previous node of the next node
            Node* prevNext = XOR(head, next->npx);
            // Update the npx of the next node
            next->npx = XOR(prevNext, head);
        }
    }

    head = newNode;
    return head;
}
Node* deleteHead(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    // Get the next node
    Node* next = XOR(nullptr, head->npx);

    // Update the npx of the next node
    if (next != nullptr) {
        Node* nextNext = XOR(head, next->npx);
        next->npx = XOR(nullptr, nextNext);
    }

    // Delete the old head node
    delete head;

    // Return the new head node
    return next;
}
Node* deleteKthNode(Node* head, int k) {
    if (head == nullptr || k < 1) {
        return head;
    }

    if (k == 1) {
        return deleteHead(head);
    }

    Node* prev = nullptr;
    Node* curr = head;
    Node* next;

    // Traverse to the kth node
    for (int i = 1; i < k && curr != nullptr; ++i) {
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }

    // If the kth node is beyond the end of the list, do nothing
    if (curr == nullptr) {
        return head;
    }

    // Get the node after the kth node
    next = XOR(prev, curr->npx);

    // Update the npx of the previous node
    Node* prevPrev = XOR(curr, prev->npx);
    prev->npx = XOR(prevPrev, next);

    // Update the npx of the next node, if it exists
    if (next != nullptr) {
        Node* nextNext = XOR(curr, next->npx);
        next->npx = XOR(prev, nextNext);
    }

    // Delete the kth node
    delete curr;

    // Return the head node
    return head;
}
/*backward traversal algorithm:
pseudocode
curr!=NULL while
cout<<curr->data;
prev=next^(curr->npx);
next=curr;
curr=prev;



*/




void printList(Node* head) {
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;

    while (curr != nullptr) {
        cout << curr->data << " ";
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    Node* head = convertarr2ll(arr);
    printList(head);
    head=insertAtHead(8,head);
    printList(head);

}