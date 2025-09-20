#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* addToEmpty(int val)
{
    Node*tmp = new Node;
    tmp->data=val;
    tmp->next=tmp;
    return tmp;
}

Node* addatBeg(Node*tail, int val)
{
    Node*tmp=new Node;
    tmp->data=val;
    tmp->next=tail->next;
    tail->next=tmp;

    return tail;
}

Node* addatEnd(Node*tail , int val)
{
    Node* tmp = new Node;
    tmp->data=val;
    tmp->next=tail->next;
    tail->next=tmp;
    tail=tmp;
    return tail;
}

Node* addatPOS(Node*tail, int pos,int val)
{
    Node*p= tail->next;
    Node*tmp = new Node;
    tmp->data=val;
    while(pos>1)
    {
        p=p->next;
        pos--;
    }
    tmp->next=p->next;
    p->next=tmp;
    if(p==tail)
    {
        tail=tail->next;
    }
    return tail;
}

void disp(Node*tail)
{
    Node*p= tail->next;


   
    do {
        cout << p->data << " ";
        p = p->next; 
    } while (p != tail->next);
    cout << endl;
}




int main()
{
    Node* tail;
    tail = addToEmpty(45);
    tail = addatBeg(tail,34);
    tail = addatBeg(tail,25);
    disp(tail);
    tail = addatEnd(tail,15);
    tail = addatEnd(tail,55);
    disp(tail);
    tail = addatPOS(tail,3,11);
    tail = addatPOS(tail,6,66);
    disp(tail);

    return 0;
}