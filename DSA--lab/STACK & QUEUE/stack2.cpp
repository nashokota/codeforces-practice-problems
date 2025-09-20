//parenthesis _1

#include <bits/stdc++.h>
using namespace std;

class Node 
{
    public:
    char data;
    Node* next;
};
class Stack
{public:
    Node*top;
    //public:
    Stack(){top =NULL;}
    void push(char x);
    char pop();
    void disp();
    int peek(int pos);
    int is_empty();
};

void Stack::push(char x)
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

char Stack::pop()
{
    char x='\0';
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

int is_balanced(Stack&stk, string exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        stk.push(exp[i]);
        else if(exp[i]==')')
        {
            if(stk.top==NULL)
            return 0;
            stk.pop();
        }
    }
    if(stk.top==NULL)
    return 1;
    else
    return 0;
}
int main()
{
    string exp = "((a+b)*(c-d))()";
    Stack stk;
    cout << is_balanced(stk,exp) <<endl;
    
    // if(stk.is_empty())
    // {
    //     cout << "The stack is  empty"<<endl;
    // }
    // else cout << "The stack is not empty"<<endl;

    return 0;
}