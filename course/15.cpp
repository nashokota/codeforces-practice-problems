#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int data1)
        {
            data=data1;
            next=nullptr;
        }
};

Node* convrt2ll(int arr[],int n)
{
    Node* head = new Node(arr[0]);
    Node*mover = head;
    for(int i=0;i<n;i++)
    {
        Node* tmp=new Node(arr[i]);
        mover->next=head;
        mover=tmp;
    }
    return head;
}

int max_value(Node* head)
{
    int x=INT_MIN;
    Node*tmp =head;
    while (tmp)
    {
        if(tmp->data>x)
        {
            x=tmp->data;
        }
        tmp=tmp->next;
    }
    return x;
}

int main()
{
    int arr[]={3,6,9,13,15,17,19};
    int n= sizeof(arr)/sizeof(arr[0]);

     Node *head = convrt2ll(arr,n);
     cout << head->data <<endl;
// max value
    cout << " The max value is : "<< max_value(head)<<endl;
    return 0;
}
