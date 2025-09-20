// delete and insert
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int data1,Node* next1)
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

Node* convertArr2LL(vector<int>&arr)
{
    Node* head= new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover = temp;
    }
    return head;
}
//removing HEAD
Node* deletehead(Node*head)
{
    Node* tmp = head;
    head=head->next;
    free(tmp);
    return head;
}

// print function
void printing(Node*head)
{
     while(head!=NULL)
    {
        cout << head->data <<" ";
        head=head->next;
    }
    cout <<endl;
}
int main()
{
    vector<int>arr ={13,26,31,45,56,63};
    Node* head = convertArr2LL(arr);
    cout<< head->data<< " "<<head->next<<endl;
    printing(head);
    head = deletehead(head);
    cout << head->data<<endl;

// printing all the values



    while(head!=NULL)
    {
        cout << head->data <<" ";
        head=head->next;
    }

    
    return 0;
}