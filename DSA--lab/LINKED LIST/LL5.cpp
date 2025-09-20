//LAB practise

//creating NODE
//convert to a LL & pointing to head
// traverse & display LL data
//length of a LL
// linear search in LL
//finding MAX value
//getting the last node
//inserting a new NODE at first
//insert new node at any position
//inserting a new NODE at last
//inserting in a sorted LL

//deleting 1st node
// deleting tail node
//deleting 'K'th node of a LL
// deleting a desired NODE value

//checking if the LL is sorted
// remove duplicates from LL
//reverse LL nodes using sliding pointer

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(){}
        Node(int d, Node *n)
        {
            data=d;
            next=n;
        }
        Node(int d)
        {
            data=d;
            next=nullptr;
        }
};

Node* create_LL(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++)
    {
        Node*tmp = new Node(arr[i]);
        mover->next=tmp;
        mover=tmp;
    }
    return head;
}

void dispLL(Node* p)
{
    while(p)
    {
        cout << p->data << "  ";
        p=p->next;
    }
    cout << endl;
}

int lengthLL(Node*p)
{
    int x=0;
    while(p)
    {
        x++;
        p=p->next;
    }
    return x;
}

void searchLL(Node*p,int x)
{
    while(p)
    {
        if(p->data == x)
        {
            cout << "Data "<<x<< " is found "<<endl;
            return ;
        }
        p=p->next;
    }
    cout << "Data "<<x<< " is not found "<<endl;
    return;
}

int find_max(Node*p)
{
    int x =INT_MIN;
    while(p)
    {
        if(p->data>x)
        {
            x=p->data;
        }
        p=p->next;
    }
    return x;
}

Node* find_last(Node*p)
{
    while(p->next!=NULL)
    {
        p=p->next;
    }
    return p;
}

Node* insert_first(Node*p)
{
    Node*t = new Node;
    int x;
    cout << "Give value to insert first :";
    cin>>x;
    t->data=x;
    t->next=p;
    p=t;

    return p;
}
Node* insert_any(Node*p )
{
    int pos,x;
    Node*t = new Node;
    Node*y = new Node;
    cout<< " Give position : "<<endl;
    cin>> pos;
    if(pos==0)
    {
        cout << " Give value to insert :"<<endl;
        cin>>x;
        t->data=x;
        t->next=p;
        p=t;
        return p;
    }
    else if(pos>0)
    {
      y=p;
      for(int i=1;i<pos-1 && p;i++)
      {
        p=p->next;
      }
      if(p)
      {
        cout << "Give value to insert :"<<endl;
        cin>>x;
        t->data=x;
        t->next=p->next;
        p->next=t;
        return y;
      }
    }
}
Node* insert_last(Node*p)
{
  
  Node*t= find_last(p);
  int x;
  cout << "Give value :"<<endl;
  cin>>x;
  Node*y=new Node;
  y->data=x;
  y->next=NULL;
  t->next=y;
  return p;
}
Node* insert_sort(Node*head,int x)
{
    Node*p=new Node;
    p=head;
    Node*q =NULL;
    while(p && p->data<x)
    {
        q=p;
        p=p->next;
    }
    Node*tmp = new Node;
    tmp->data=x;
    tmp->next=q->next;
    q->next=tmp;

    return head;
}

Node* delete_first(Node*head)
{
    
    head=head->next;
    return head;
}
Node* delete_tail(Node*head)
{
    Node*tmp = head;
    if(tmp==NULL || tmp->next == NULL)
    return NULL;
    while(tmp->next->next!=NULL)
    {
        tmp=tmp->next;
    }
    free(tmp->next);
    tmp->next=nullptr;
    return head;
}
Node* delete_any(Node*head, int x)
{
    if(head==NULL)return head;
    if(x==1)
    {
        head=head->next;
        return head;
    }
    int count=0;
    Node*tmp =new Node;
    tmp=head;
    Node*prev=NULL;
    while(tmp)
    {
        count++;
        if(count == x)
        {
            prev->next=tmp->next;
            free(tmp);
            break;
        }
        prev=tmp;
        tmp=tmp->next;
    }
    return head;
}
Node* delete_val(Node*head, int key)
{
    if(head==NULL)return head;
    
    if(head->data==key)
    {
        head=head->next;
        return head;
    }
    Node* tmp=head;
    Node*prev=NULL;
    while(tmp)
    {
        if(tmp->data==key)
        {
            prev->next=prev->next->next;
            free(tmp);
            break;
        }
        prev=tmp;
        tmp=tmp->next;
    }
    return head;
}


int main()
{
    vector<int>arr={10,20,30,90};

    cout << "...Creating our Linked  List..."<<endl;
    Node * head = create_LL(arr);
    dispLL(head);

    head = insert_sort(head,56);
    dispLL(head);
    head = insert_sort(head,57);
    dispLL(head);
    head = insert_sort(head,55);
    dispLL(head);
    head = insert_sort(head,65);
    dispLL(head);
    head = insert_sort(head,60);
    dispLL(head);

    head=delete_first(head);
    dispLL(head);

    head = delete_tail(head);
    dispLL(head);

    head = delete_any(head,3);
    dispLL(head);
    head = delete_any(head,3);
    dispLL(head);

     head = insert_last(head);
    dispLL(head);
    return 0;
}