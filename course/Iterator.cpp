// ITERATORS //
#include <bits/stdc++.h>
using namespace std;



int main()
{
    vector<int> v= {1,2,3,4,5,6};
  vector<int>::iterator it = v.begin();
  cout << (*it) <<endl;
  it = v.end(); //returns an iterator pointing to the element after the last element of the container.
  cout << (*it) <<endl;  
  it--;
  cout << (*it)<<endl;

  auto ite = v.begin(); // same as before
  auto itr =  v.rbegin(); // reverse iterator pointing to the last element of the container

  // can go to the next element using next and previous element using prev
    itr=next(itr);
    cout << (*itr)<<endl;
    itr=next(itr);
    cout << (*itr)<<endl;

    //iterator will be invalided if the container is modified

    // vector traverse 
    vector<int>arr ={22,23,24,25,26,27,30};
    vector<int>:: iterator iter= arr.begin();
    for(;iter!=arr.end();iter++)
    {
        cout << (*iter)<<" ";
    }
    cout << endl;
    
    //another traverse
    for(auto x:arr){
        cout << x <<" ";
    }
    cout <<endl;
    return 0;
}