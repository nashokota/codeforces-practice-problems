// All together about ARRAY //

#include <bits/stdc++.h>
using namespace std;

class ARRay
{
    private:
        int *A;
        int size;
        int length;
        void swapp(int *x,int *y)
        {
            int tmp=*x;
            *x=*y;
            *y=tmp;
        }
    public:
        ARRay()
        {
            size=10;
            length=0;
            A=new int[size];
        }
        ARRay(int sz)
        {
            size=sz;
            length=0;
            A=new int [size];
        }
        ~ARRay()
        {
            delete []A;
        }
// member functions
void Display();
void Append(int x);
void Insert(int index,int x);
int Delete(int index);
int LinearSearch(int key);
int BinarySearch(int key);
// int RBinSearch(int ar[],int l,int h,int key);
int Get(int index);
void Set(int index,int x);
int Max();
int Min();
// float Avg();
// void Reverse();
// void Reverse2();
void InsertSort(int x);
int is_Sorted();
void Rearrange();
};

void ARRay::Display()
{
    int i;
    cout << "Elements are : "<<endl;
    for(i=0;i<length;i++)
    {
        cout << A[i]<< " ";
    }
}

void ARRay::Append(int x)
{
    if(length<size)
        A[length++]=x;
}

void ARRay::Insert(int index,int x)
{
    if(index>=0 && index<=length)
    {
        for(int i=length;i>index;i--)
        {
            A[i]=A[i-1];
        }
        A[index]=x;
        length++;
    }
}

int ARRay:: Delete(int index)
{
    int x=0;
    if(index>=0 && index< length )
    {
        x=  A[index];
        for(int i=index;i<length-1;i++)
        {
            A[i]=A[i+1];
        }
        length--;
        return x;
    }
    return 0;
}

int ARRay::LinearSearch(int key)
{
    int x=0;
    for(int i=0;i<length;i++)
    {
        if(A[i]==key)
        {
            x=1;
        }
    }
    return x;
}

int ARRay:: BinarySearch(int key)
{
    int l,h,m;
    l=0;
    h=length-1;
    while(l<=h)
    {
        m=(l+h)/2;
        if(key==A[m])
        {
            return m;
        }
        else if(key>A[m])
        {
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    return -1;
}

int ARRay::Get(int index)
{
    if(index>=0 && index<length)
    return A[index];
    return -1;
}

void ARRay::Set(int index,int x)
{
    if(index>=0 && index<length)
    A[index]=x;
}

int ARRay::Max()
{
    int x=0;
    for(int i=0;i<length;i++)
    {
        if(x<A[i])
        {
            x=A[i];
        }
    }
    return x;
}

int ARRay::Min()
{
    int x=100000000;
    for(int i=0;i<length;i++)
    {
        if(x>A[i])
        {
            x=A[i];
        }
    }
    return x;
}

void ARRay::InsertSort(int x)
{
    int i=0;
    for(i=length-1;A[i]>x;i--)
    {
           A[i+1]=A[i]; 
    }
    A[i+1]=x;
}

int ARRay::is_Sorted()
{
    
    for(int i=0;i<length-1;i++)
    {
        if(A[i]>A[i+1])
        {
            return -1;
        }
    }
    return 1;
}

void ARRay::Rearrange()
{
    int i=0;
    int j=length-1;
    while (i<j)
    {
        while(A[i]<0)
        {
            i++;
        }
        while(A[j]>0)
        {
            j--;
        }
        if(i<j)
        {
            int tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
}
int main()
{
    ARRay *arr1;
    int ch,sz;
    int x,index;

    cout <<"Enter Size of Array";
    cin>>sz;
    arr1=new ARRay(sz);
    do
    {
        cout << "\n\nMenu\n\n";
        cout << "1. Insert \n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "enter your choice :";
        cin>>ch;

        switch(ch){
            case 1: printf("Enter an element and index");
              scanf("%d%d",&x,&index);
            arr1->AppendInsert(index,x);
            break;
            case 2: printf("Enter index ");
            scanf("%d",&index);
            x=arr1->ADelete(index);
            printf("Deleted Element is %d\n",x);
            break;
            case 3:printf("Enter element to search ");
            scanf("%d",&x);
            index=arr1->LinearSearch(x);
            printf("Element index %d",index);
            break;
            case 4:printf("Sum is %d\n",Sum(arr1));
            break;
            case 5:Display(arr1);
        }
    }while()
    return 0;
}