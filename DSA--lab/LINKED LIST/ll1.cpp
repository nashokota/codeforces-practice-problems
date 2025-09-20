// basic of LL
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

// pointing to the head value 
Node* convertArr2LL(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp =new Node(arr[i]);
        mover->next = temp;
        mover =temp;
    }
    return head;
}
//length of a LL
int lengthofLL(Node* head)
{
    int cnt=0;
    Node*tmp=head;
    while(tmp)
    {
        cnt++;
        tmp=tmp->next;
    }
    return cnt;
}

int LLsearch(Node* head, int value)
{
    Node* tmp =head;
    while(tmp)
    {
        if(tmp->data==value)
        return 1;
        tmp=tmp->next;
    }
    return 0;
}
int main()
{
    vector<int>arr = {12,5,8,7};
    Node*y = new Node(arr[0]);
    cout <<y;  // memory location is printed 
    cout <<endl;
    Node z = Node(arr[1],nullptr);
    // cout << z ;   .....wrong cz its an object
    cout << z.data<< " "<<z.next<<endl;

    Node* head = convertArr2LL(arr);
    cout << head->data<<endl; // print the head value 
 
    //array traverse using linked list
    Node *tem = head;
    while(tem)
    {
        cout << tem->data<< " ";
        tem=tem->next;
    }
cout <<endl;  
    //length of LL
    int length = lengthofLL(head);
    cout << "Length is :"<<length<<endl;

    // search in a LL
    int val;
    cout << "Give value to search :";
    cin>>val;
    int s= LLsearch(head,val);
    if(s==1)cout << "FOUND"<<endl;
    else cout << "NOT FOUND"<<endl;
    return 0;
}