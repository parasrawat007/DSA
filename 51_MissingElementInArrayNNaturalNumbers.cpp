/*
    Array = {1,2,3,4,5,7,8,9,10}
    find missing element
*/

#include<iostream>
using namespace std;

int main()
{
    int A[] = {1,2,3,4,5,7,8,9,10};
    
    int sum=0,s,n=A[8];

    for (int i = 0; i < 9; i++)
    {
        sum+=A[i];
    }

    s=n*(n+1)/2;

    s=s-sum;

    cout<<"Missing element = "<<s;

    return 0;
}