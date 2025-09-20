#include<bits/stdc++.h>
using namespace std;

class Array
{
    int size;
    int *arr;
public:
    Array(int size)
    {
        arr=new int[size];
    }

    void create_array(int size)
    {
        delete []arr;
        this->size=size;
        arr=new int[size];

        for(int i=0; i<size; i++)
            arr[i]=0;
    }

    void insert_element(int index, int value)
    {
        if(index>size || index<0)
        {
            cout<<"Invalid index"<<endl;
            return;
        }
        else
        {
        int *temp=new int[size+1];
        for(int i=0; i<size; i++)
        {
            temp[i]=arr[i];
        }
        for(int i=size; i>=index; i--)
        {
            if(i==index)
            {
                temp[i]=value;
            }
            else {
                temp[i]=temp[i-1];
            }
        }
        size++;
        delete []arr;
        arr=temp;
        }
    }


    void delete_element(int index)
    {
        if(index<0 || index>=size)
            {
                cout<<"Invalid index"<<endl;
            }
        else
        {
            for(int i=index; i<size-1; i++)
                {
                    arr[i]=arr[i+1];
                }
            size--;
        }
    }


    int search_element(int value)
    {
        for(int i=0; i<size; i++)
            {
                if(arr[i]==value)
                    return i;
            }

        return -1;
    }


    void traverse_array()
    {
        cout<<"Array : ";
        for(int i=0; i<size; i++)
            {
                cout<<arr[i]<<"  ";
            }
    }

    ~Array()
    {
        delete []arr;
    }
};

int main()
{
    Array a(4);
    a.create_array(5);

    a.traverse_array();
cout << endl;
cout << "--Inserting new elements in Array-- "<<endl;
    a.insert_element(2,5);
    a.insert_element(3,7);

    a.traverse_array();
    cout <<endl;
    int j;
    cout << "Which index do you want to delete ? "<<endl;
    cin>>j;
    a.delete_element(j);

    cout<<"After deletion a index :"<<endl;
    a.traverse_array();
cout << endl;

    int n,m;
    cout << "Which value do you want to search ? "<<endl;
    cin >> n;
    m= a.search_element(n);
    if(n==-1)
        cout<<"Element not found"<<endl;
    else
  {
          cout<<"Element found at index: "<< m <<endl;
  }
}