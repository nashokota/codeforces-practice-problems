//n = n | (1u << k);
//
//This line performs a bitwise OR operation (|) between the value of n 
//and the result of shifting the integer 1 left by k positions (1u << k). 
//This operation sets the k-th bit of n to 1.

#include<iostream>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    unsigned int n, k; cin >> n >> k;
    n = n | (1u << k);
    cout << n << '\n';
  }
  return 0;
}