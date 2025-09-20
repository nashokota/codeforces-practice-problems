// sum of all elements in a LL
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node*next;
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

Node* convrt2ll(int arr[], int n)
{
    Node*head=new Node(arr[0]);
    Node*mover= head;
    for(int i=1;i<n;i++)
    {
        Node*tmp=new Node(arr[i]);
        mover->next=tmp;
        mover=tmp;
    }
    return head;
}

// sum function
int sumofall(Node*head)
{
    int sum=0;
    
    while (head)
    {
        sum=sum+head->data;
        head=head->next;

    }
    return sum;
}

int Rsum(Node*head)
{
    if(head==0)
    {
        return 0;
    }
    else
    return Rsum(head->next)+ head->data;
}
//max value 
int MAX_val(Node*head)
{
    int max=INT_MIN;
    while(head)
    {
        if(head->data>max)
        max=head->data;
        head=head->next;
    }
    return max;
}

//max value recursion
int R_max(Node*p)
{
    int x=0;
    if(p==0)
    {
        return INT32_MIN;
    }
    x= R_max(p->next);
    if(x>p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}
// searching in a LL (binary searching isnt possible)
Node* searchLL(Node*p,int key)
{
    while(p!=NULL)
    {
        if(p->data==key)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

//improve searching .... transposition
Node* search_improve(Node*p,int key)
 {
    Node*q=NULL;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
          //  first=p;
        }
        q=p;
        p=p->next;
    }
 }
int main()
{
    int arr[]={1,3,5,7,9,11,13,15,17};
    int n= sizeof(arr)/sizeof(arr[0]);

    Node * head = convrt2ll(arr,n);
    cout << head->data << "  "<< head->next;

    // sum of elements

    int sum = sumofall(head);
    cout << "The sum is : "<<sum << endl;
    cout << Rsum(head)<<endl;

    //max value
    cout << " the max value is :"<< MAX_val(head)<<endl;
    cout << " the max value is :"<< R_max(head)<<endl;

    //searching 
    Node* ser = searchLL(head,11);
    if(ser==NULL)
    {
        cout << "NOT FOUND"<<endl;
    }
    else
    {
        cout << "FOUND"<<ser->data<<endl;
    }
    return 0;
}