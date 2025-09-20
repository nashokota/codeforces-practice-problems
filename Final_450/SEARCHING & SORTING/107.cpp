// Find missing and Repeating of a given array 
/*
        Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
*/

// MATHEMATICAL APPROACH:

// 1. Assume you have two arrays - 1 which is provided to you and the other imaginary array contains number from 1 to N.

// 2. Deduce 2 equations - (summation of array elements of array1 - summation of array elements of array2) and (summation of squares of array elements of array1 - summation of squares of array elements of array2).

// 3. You can dry run and will find that first eq gives missing no - repeating, and second eq give (missing no)^2 - (repeating no)^2.

// 4. Now just solve these 2 equations to obtain your answer.



#include <bits/stdc++.h>
using namespace std;

void find_it(vector<int>arr,int n)
{
    long long N =n;
    long long as =0 , asq=0;
    long long es = (N*(N+1))/2;
    long long esq = (N*(N+1)*(2*N+1))/6;

    for ( int i=0;i<arr.size();i++)
    {
        as+= arr[i];
        asq+= (long long)arr[i]*(long long )arr[i];
    }

    long long val1 =as-es;
    long long val2 = asq-esq;
    val2 = val2/val1;
    long long repeating = (val1+val2)/2;
    long long missing = repeating-val1;

    cout << repeating <<" "<< missing<<endl;
}

int main()
{
    int n=16;
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,11,13,14,15,16};
    cout << "Repeating" << " Missing "<<endl;
    find_it(arr,n);
    return 0;
}