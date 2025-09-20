#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node*xorPtr;
};

Node*xorPtr(Node*a, Node*b)
{
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a)^ reinterpret_cast<uintptr_t>(b));
}

//function to traverse 
void traversal(Node *head)
{
    Node*prev=nullptr;
    Node*cur = head;
    Node*next;

    cout << "Forward travarsal :"<<endl;
    while(cur)
    {
        cout << cur->data<< " ";
        next = xorPtr(prev,cur->xorPtr);
        prev = cur;
        cur = next;
    }
    cout <<endl;
}
int main()
{
    Node*head = new Node{1,nullptr};
    Node* second = new Node{2,nullptr};
    Node* third = new Node{3,nullptr};
    Node* tmp = new Node{69,nullptr};
    head->xorPtr = xorPtr(nullptr,second);
    second->xorPtr = xorPtr(head,third);
    third->xorPtr=xorPtr(second,tmp);
    tmp->xorPtr = xorPtr(third,nullptr);

    traversal(head);

    return 0;
}