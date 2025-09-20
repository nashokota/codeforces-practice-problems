#include <bits/stdc++.h>
using namespace std;

class Node 
{
    public:
    int data;
    Node* next;
};
class Stack
{
    Node*top;
    public:
    Stack(){top =NULL;}
    void push(int x);
    int pop();
    void disp();
    int peek(int pos);
    int is_empty();
};

void Stack::push(int x)
{
    Node *t = new Node;
    if(t==NULL)
    {
        cout << "Stack is overloaded"<<endl;
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::pop()
{
    int x=-1;
    if(top==NULL)
    {
        cout << "Stack is empty"<<endl;
    }
    else{
        x=top->data;
        top=top->next;
    }
    return x;
}

void Stack::disp()
{
    Node*p=top;
    while(p)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}

int Stack::peek(int pos)
{
    Node*p;
    p=top;
    for(int i=0;p!=NULL & i<pos-1;i++)
    p=p->next;

    if(p!=NULL)
    {
        return p->data;
    }
    else
    return -1;
}

int Stack::is_empty()
{
    return top? 0:1;
}
int main()
{
    Stack stk;
    stk.push(1);
    stk.push(11);
    stk.push(12);
    stk.push(13);
    stk.push(15);

    stk.disp();

    stk.pop();
    stk.disp();

    stk.push(19);
    stk.push(21);
    stk.push(24);
    stk.push(33);
    stk.push(25);

    stk.disp();
    cout << "The value at 4th position is :" <<stk.peek(4)<<endl;

    
    if(stk.is_empty())
    {
        cout << "The stack is  empty"<<endl;
    }
    else cout << "The stack is not empty"<<endl;

    return 0;
}