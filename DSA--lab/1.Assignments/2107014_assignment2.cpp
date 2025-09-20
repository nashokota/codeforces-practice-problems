#include<iostream>
#include<cmath>
using namespace std;
class Array{
    int size;
    int *arr;
public:
    Array(int size)
    {
        this->size=size;
        arr=new int[size];
    }

    void create_array(int size)
    {
        this->size=size;
        arr=new int[size];
        cout<<"Enter the array elements :"<<endl;
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
    }
    void insert_Element(int index,int value)
    {
        if((index<=0)||(index>=size))
           {
               cout<<"Invalid insertion "<<endl;
           }
       else{

    for (int i = size-1; i >=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = value;
    cout<<"Element inserted successfully"<<endl;
    size++;

       }
    }
    void delete_Element(int index)
    {
        if((index<=0)||(index>=size))
           {
               cout<<"Invalid deletation "<<endl;
           }
        else
          {
          for (int i = index; i < size-1; i++)
        {
        arr[i] = arr[i + 1];
        }
        cout<<"Elemnt deleted successfully"<<endl;
        size--;
    }

    }

    int search_element(int value)
    {
        int x=-1;
        for(int i=0;i<size;i++)
        {
            if(arr[i]==value)
            {
                x=i;
                return i;
            }
        }
            return x;
    }
    void traverseArray()
    {
        for (int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }

    int binary_search(int value)
    {
        string x="Array is not sorted\n";
        int flag=0;
        if(size>=1)
        {
        for (int i=1;i<size;i++)
            {
            if (arr[i-1]>arr[i])
                {
                  flag=-1;
                  break;
                }
            }

    try
      {
        if(flag==-1)
        {
            throw x;

        }
      }
    catch(string x)
      {
        cout<<x;
        return 0;
      }
        }
        int l=0;
        int u=size-1;

  while (l<=u) {
    int mid=(l+u)/2;

    if (arr[mid]==value)
      return mid;

    if (arr[mid]<value)
      l=mid+1;
     else
      u=mid-1;
  }

  return -1;
}
int lower_bound(int value)
{
        string x="Array is not sorted\n";
        int flag=0;
        int l=0;
        int lb=size;
        int h=size-1;
         if(size>=1)
        {
        for (int i=1;i<size;i++)
            {
            if (arr[i-1]>arr[i])
                {
                  flag=-1;
                  break;
                }
            }

    try
      {
        if(flag==-1)
        {
            throw x;

        }
      }
    catch(string x)
      {
        cout<<x;
        return 0;
      }
        }
        if(arr[0]>value)
        {
            return -1;
        }
        if(arr[0]==value)
            return -2;

        while(l<=h){
            int mid=(l+h)/2;

            if(arr[mid]>=value){
                lb=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return lb;
    }
    int upper_bound(int value)
{
        string x="Array is not sorted\n";
        int flag=0;
        int l=0;
        int ub=size;
        int h=size-1;
         if(size>=1)
        {
        for (int i=1;i<size;i++)
            {
            if (arr[i-1]>arr[i])
                {
                  flag=-1;
                  break;
                }
            }

    try
      {
        if(flag==-1)
        {
            throw x;

        }
      }
    catch(string x)
      {
        cout<<x;
        return -2;
      }
        }
        if(arr[h]<=value)
        {
            return -1;
        }

        while(l<=h){
            int mid=(l+h)/2;

            if(arr[mid]>value){
                ub=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ub;
    }

int one_sided_bsearch(int value)
{
    int n = size -1;
    int lg = log2(n-1) +1;
    int pos =0;
    for(int i=lg;i>=0;i--)
    {
        if(arr[pos]== value)
        return pos;

        int new_pos = pos | (1<<i);

        if((new_pos<n) && (arr[new_pos] <= value))
        pos=new_pos;
    }

    return ((arr[pos]== value)? pos : -1);
}

      ~Array()
    {
        delete[] arr;
    }

};
int main()
{
    int x,s,i,e,c;
    Array ar(s);

    while(1)
    {
        cout<<"Array operations :"<<endl;
        cout<<"1.Create an array"<<endl;
        cout<<"2.Insert an element"<<endl;
        cout<<"3.Delete an element"<<endl;
        cout<<"4.Search an element"<<endl;
        cout<<"5.Traverse the array"<<endl;
        cout<<"6.Search an element using binary search"<<endl;
        cout<<"7.Lower bound "<<endl;
        cout<<"8.Upper bound "<<endl;
        cout<<"9.Search using one sided binary search"<<endl;
        cout<<"\nEnter your choice"<<endl;
        cin>>x;
        switch(x)
        {
        case 1:
            cout<<"Enter the array size"<<endl;
            cin>>s;
            ar.create_array(s);
            cout<<"\n"<<endl;
            break;

         case 2:
            
            cout<<"Enter index"<<endl;
            cin>>i;
            cout<<"Enter element"<<endl;
            cin>>e;
            ar.insert_Element(i,e);
            cout<<"\n"<<endl;

            break;

        case 3:
            cout<<"Enter the index"<<endl;
            cin>>i;
            ar.delete_Element(i);
            cout<<"\n"<<endl;

            break;
        case 4:
            cout<<"Enter the element to be searched"<<endl;
            cin>>e;
            c=ar.search_element(e);
            if(c!=-1)
            cout<<"Element "<<e<<" was found at index "<<c<<endl;
            else
                cout<<"Element was not found"<<endl;
            cout<<"\n"<<endl;
            break;
        case 5:
            cout<<"Displaying the array\n"<<endl;
            ar.traverseArray();
            cout<<"\n"<<endl;
            break;
        case 6:
            cout<<"Enter the element to be searched"<<endl;
             cin>>e;
            c=ar.binary_search(e);
            if(c>0)
            cout<<"Element "<<e<<" was found at index "<<c<<endl;
            else if(c==-1)
                cout<<"Element was not found"<<endl;
                else
                    cout<<"Error Detected"<<endl;
            cout<<"\n"<<endl;
            break;

        case 7:
            cout<<"Enter the element "<<endl;
             cin>>e;
            c=ar.lower_bound(e);
            if(c>0)
            cout<<"Element "<<e<<" with lower bound index "<<c<<endl;
            else if(c==-1)
                cout<<"This is less than the smallest element of the array"<<endl;
            else if(c=-2)
                cout<<"This is the smallest element of the array at index 0"<<endl;
                 else
                    cout<<"Error detected"<<endl;
            cout<<"\n"<<endl;
            break;

        case 8:
            cout<<"Enter the element to be searched"<<endl;
             cin>>e;
            c=ar.upper_bound(e);
            if(c>0)
            cout<<"Element "<<e<<" with upper bound index "<<c<<endl;
            else if(c==-1)
                cout<<"This is the largest element of the array"<<endl;
                else if(c==0)
                    cout<<"The element is less than the smallest element of the array"<<endl;
                else
                    cout<<"Error detected "<<endl;
            cout<<"\n"<<endl;
            break;
            case 9:
            cout<<"Enter the element to be searched"<<endl;
            cin>>e;
            c=ar.one_sided_bsearch(e);
            if(c!=-1)
            cout<<"Element "<<e<<" was found at index "<<c<<endl;
            else
                cout<<"Element was not found"<<endl;
            cout<<"\n"<<endl;
            break;
        default:
            cout<<"Invalid choice\n\n"<<endl;
        }

             }
    return 0;
}
