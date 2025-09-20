// recursive function //
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
    public:
        Node(int data1, Node* next1)
        {
            data=data1;
            next=next1;
        }
        Node(int data1)
        {
            data=data1;
            next=nullptr;
        }
};

Node* convert2LL(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++)
    {
        Node*tmp=new Node(arr[i]);
        mover->next=tmp;
        mover=tmp;
    }
    return head;
}

void display(Node*p)
{
    if(p!=NULL)
    {
        // printing in reverse
        //display(p->next);
        cout << p->data << " ";
        //p=p->next;
        // printing serially
         display(p->next);
    }
}

//length,number of nodes
int length_LL(Node*head)
{
    int cnt=0;
    while(head!=NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}

// length using recurssion
int COUNT(Node*p)
{
    if(p==0)
    return 0;
    else 
    return 1+COUNT(p->next);    //return COUNT(p->next)+1;
}
int main()
{
    vector<int>arr ={8,3,7,12,9};

    //creating LL
    Node*head = convert2LL(arr);
    //display
    
    display(head);

    int len =length_LL(head);
    cout << "Length of LL :"<<len <<endl;
    int count = COUNT(head);
    cout << " count is :"<<count <<endl;
    return 0;
}