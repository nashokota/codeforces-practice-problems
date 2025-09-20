// STACK //
#include <bits/stdc++.h>
using namespace std;



int main()
{
 stack<int> st;
 st.push(10);
 st.push(20);
 st.push(30);

 st.push(11);
 st.pop();
  cout << " Top element of the stack "<<st.top()<<endl;
  cout << " Size of stack "<<st.size()<<endl;
  cout << "Is the stack empty ? "<< (st.empty()?"YES":"NO")<<endl;

  //swap

  stack<int> str;
  str.push(1);
  str.push(2);
  str.push(3);
  str.push(4);

  st.swap(str);

  // print stack from top to bottom 
  cout << "Stack element from top to bottom :"<<endl;
  while (!st.empty())
  {
    cout << st.top()<<" ";
    st.pop();
  }
  cout <<endl;

  cout << st.size()<<endl;
  cout << str.size()<<endl;
    return 0;
}