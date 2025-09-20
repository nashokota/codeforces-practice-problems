#include<bits/stdc++.h>
using namespace std;

template<class T>
struct Node{
    T data;
    Node *next;
};

template<class T>
class Linked_list{
   Node<T> *head;

   public:

   Linked_list(){
      head=NULL;
   }

   ~Linked_list(){
        Node<T> *curr=head,*prevNode;

        while (curr!=NULL){
          prevNode=curr;
          curr=curr->next;
          delete prevNode;
        }
        head=NULL;
   }

   void insert_first(const T& value){
        Node<T> *newNode=new Node<T>;
        newNode->data=value;
        newNode->next=head;
        head=newNode;
   }

    void insert_last(const T& value){

        if(head==NULL){
        Node<T> *newNode=new Node<T>;
        newNode->data=value;
        newNode->next=NULL;
        head=newNode; 
        }
        
        else{
        Node<T> *newNode = new Node<T>,*curr=head;
        newNode->data=value;
        newNode->next=NULL;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=newNode;
        }
    }

    void insertAtPosition(int pos,const T& value){
        Node<T> *newNode=new Node<T>,*curr=head,*prevNode;
        newNode->data=value;
        int sz=getLength();
        
        if(pos>sz){
            cout<<"position out of bounds\n";
        }
        else if(pos==1){
            insert_first(value);
        }
        else{
        while(pos!=1){
            prevNode=curr;
            curr=curr->next;
            pos--;
        }
        newNode->next=curr;
        prevNode->next=newNode;
        }
    }

  bool search(const T& value)const{
      Node<T> *curr=head;

      while(curr!=NULL){
        if(curr->data==value) return true;
         curr=curr->next;
      }
      return false; 
  }

void display()const{
     Node<T> *curr=head;
     cout<<"Display all the elements of the list: ";

     while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
     }
     cout<<"\n";
}

int getLength()const{
    int cnt=0;
    
     Node<T> *curr=head;

     while(curr!=NULL){
        curr=curr->next;
        cnt++;
     }
     return cnt;
}   
};