#include <bits/stdc++.h>
using namespace std;

//creating NODE
class Node
{
    public:
        int data;
        Node* next;
    public:
        Node(){}
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


//convert to a LL & pointing to head
Node* convert2LL(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node*mover =head;
    for(int i=1;i<arr.size();i++)
    {
        Node* tmp = new Node(arr[i]);
        mover->next=tmp;
        mover=tmp;
    }
    return head;
}


// traverse & display LL data
void dispLL(Node*p)
{
    while(p)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout <<endl;
}


//length of a LL
int length_LL(Node*p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}
//length of a LL using recursion
int length_LL2(Node*p)
{
   if(p==0)
   {
    return 0;
   }
   else{
    return 1 + length_LL2(p->next);
   }
}


// linear search in LL
Node* searchLL(Node*p,int key)
{
    while(p)
    {
        if(p->data==key)
        {
            return p;
        }
        p=p->next;
    }
    return p;
}


// sum of all the node values
int sum_Nodes(Node*p)
{
    int sum =0;
    while(p)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
// sum values using recursion 
int sum_Nodes2(Node*p)
{
    if(p==NULL)
    return 0;
    else
    return p->data + sum_Nodes2(p->next);
}

//finding MAX value
int find_max(Node*p)
{
    int x=INT_MIN;
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
//finding MAX value using recursion 
int find_max2(Node*p)
{
    int x=0;
    if(p==0)
    {
        return INT32_MIN;
    }
    x= find_max2(p->next);
    if(x>p->data)
    return x;
    else 
    return p->data;
}

//getting the last node 
Node* last_node(Node*head)
{
    while(head->next!=NULL)
    {
        head=head->next;
    }
    return head;
}

//inserting a new NODE at first 
Node* insert_first(Node*p)
{
    int x;
    cout << "Give the  value you want to add : "<<endl;
    cin>>x;
    Node*tmp = new Node;
    tmp->data=x;
    tmp->next=p;
    p=tmp;
    return p;
}
//insert new node at any position 
void insert_node(Node*p)
{
    Node*t,*y;
    int pos;
    cout << " Give position to insert :"<<endl;
    cin>>pos;
    if(pos==0)
    {
        t=new Node;
        cout <<"Give your value :"<<endl;
        cin>>t->data;
        t->next=p;
        p=t;
    }
    else if (pos>0)
    {
        y=p;
        for(int i=0;i<pos-1 && p;i++)
        {
            p=p->next;
        }
        if(p)
        {
            t=new Node;
            cout << "Give your value :"<<endl;
            cin>>t->data;
            t->next=p->next;
            p->next=t;
        }
    }
}
//inserting in a SORTED LL
Node* insert_sorted(Node*head,int x)
{
    Node*p = new Node;
    p=head;
    Node*q =NULL;
    while(p && p->data<x)
    {
        q=p;
        p=p->next;
    }
    Node* tmp = new Node;
    tmp->data =x;
    tmp->next=q->next;
    q->next=tmp;
    return head;
}


//creating LL by inserting at last
// void insert_last(Node*p, int x)
// {
//     Node*t=new Node;
//     t->data=x;
//     t->next=NULL;
//     if(p==NULL)
//     {
//         p=
//     }
// }

//creating a LL

//deleting 1st node
Node* delete_first(Node*p)
{
    Node* tmp = p;
    p=p->next;
    free(tmp);
    return p;
}
// deleting tail node
Node* delete_tail(Node* head)
{
    if(head==NULL || head->next==NULL)
    return NULL;
    Node* tmp = head;
    while(tmp->next->next!= NULL)
    {
        tmp=tmp->next;
    }
    free(tmp->next);
    tmp->next=nullptr;
    return head;
}
//deleting 'K'th node of a LL
Node* delete_k(Node* head , int k)
{
    if(head==NULL)return head;
    if(k==1)
    {
        Node* tmp =head;
        head=head->next;
        free(tmp);
        return head;
    }
    int count =0;
    Node* prev= NULL;
    Node* tmp =head;
    while(tmp)
    {
        count ++;
        if(count == k)
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
// deleting a desired NODE value
Node* delete_element(Node* head , int key)
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

//checking if the LL is sorted
void is_sorted(Node*head)
{
    int x=INT_MIN;
    Node* p = new Node;
    p=head;
    while(p)
    {
        if(p->data<x)
        {
            cout << "LL is not sorted"<<endl;
            return;
        }
        else{
            x=p->data;
            p=p->next;
        }
    }
    cout << " LL is Sorted "<<endl;
}

// remove duplicates from LL
void remove_dupli(Node*head)
{
    Node*p =new Node;
    p=head;
    Node*q = head->next;
    while(q)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

//reversing elements of LL
    void reverse_elements (Node*head)
    {
        Node*p=new Node;
        p=head;
        int arr[100];
        int i=0;
        while (p)
        {
            arr[i]=p->data;
            p=p->next;
            i++;
        }
        p=head;
        i--;
        while(p)
        {
            p->data=arr[i];
            p=p->next;
            i--;
        }
    }
    //reverse LL nodes using sliding pointer
    void reverse_nodes(Node*head)
    {
        Node*p=new Node;
        p=head;
        Node*q=NULL;
        Node*r=NULL;
        
        while(head)
        {
            r=q;
            q=head;
            head=head->next;
            q->next=r;
        }
        p=head;
    }

int main()
{
    vector<int>arr={12,14,16,18,21,23,25,27,33,44};

    //convert2LL and pointing head
    Node* head= convert2LL(arr);
    cout << "The first data of LL :"<<head->data<<endl;

    //traverse the LL and display
    cout << " Our First LL values :"<<endl;
    dispLL(head);

    //length of a LL
    cout<< "The length of LL : "<< length_LL(head)<<endl;

    // linear search in LL
    int n;
    cout << "Which value to search :"<<endl;
    cin>>n;
    Node* search =searchLL(head,n);
    if(search)
    cout << "FOUND "<<" "<<search->data<<endl;
    else
    cout << " NOT FOUND"<<endl;

    //deleting first node of LL
    head = delete_first(head);
    cout << " LL after deleting First Node : "<<endl;
    dispLL(head);

    //sum of all node values
    cout << " Sum of all Node values : "<< sum_Nodes(head)<<endl;
    cout << " Sum of all Node values : "<< sum_Nodes2(head)<<endl;

    //finding MAX value
    cout << " MAX value in our LL :"<< find_max(head)<<endl;
    cout << " MAX value in our LL :"<< find_max2(head)<<endl;

    // inserting NODE at first
    head= insert_first(head);
    cout << " after insertion complete :"<<endl;
    dispLL(head); 
    cout<< "The length of LL : "<< length_LL(head)<<endl;
    // inserting at any position 
     insert_node(head);
    cout << "After insertion : "<<endl;
    dispLL(head);

    //getting last node
    Node*tail = last_node(head);
    cout << " The last node value is :"<<tail->data<<endl;

    //delete tail 
    head = delete_tail(head);
    cout << " After deleting the tail :"<<endl;
    dispLL(head); 

    //deleting 'K'th node of a LL
    head = delete_k(head,4);
    cout << "After deleting 4th node :"<<endl;
    dispLL(head);
    head = delete_k(head,8);
    cout << "After deleting 8th node :"<<endl;
    dispLL(head);
    head = delete_k(head,14);
    cout << "After deleting 14th node :"<<endl;
    dispLL(head);

    //deleting a dersired Node value
    cout << "Which value you want to delete "<<endl;
    int x;
    cin>>x;
    delete_element(head,x);
    cout << "After deleting the value :"<<endl;
    dispLL(head);

    // check if the LL is Sorted
    vector<int>arr1 ={3,5,7,9,11,21,15,17};
    Node* head1 = convert2LL(arr1);
    is_sorted(head1);
    dispLL(head1);

    // Removing duplicates from LL
    arr1={3,5,5,5,7,8,9,9,10};
    head1 = convert2LL(arr1);
    remove_dupli(head1);
    cout << "After removing duplicate Nodes :"<<endl;
    dispLL(head1);

    //reversing elements of LL
    reverse_elements(head1);
    cout << " After reversing the elements of LL :"<<endl;
    dispLL(head1);

//this function isnt working
    //reversing NODES of LL
    arr1={4,6,8,12,14,16,18};
    head1= convert2LL(arr1);
    reverse_nodes(head1);
    cout << "After reversing :"<<endl;
     dispLL(head1);

//this function is working now
    //inserting in a sorted LL
    insert_sorted(head,99);
    cout << "After inserting the values :"<<endl;
    dispLL(head);
    insert_sorted(head,100);
    cout << "After inserting the values :"<<endl;
    dispLL(head);
    insert_sorted(head,95);
    cout << "After inserting the values :"<<endl;
    dispLL(head);

    


    return 0;
}