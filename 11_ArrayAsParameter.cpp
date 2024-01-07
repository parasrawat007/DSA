#include<iostream>
using namespace std;
void fun(int A[],int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<A[i]<<endl;
    }
    A[4]=11;
}
void fun1(int *A,int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<A[i]<<endl;
    }
    A[4]=0;
}
int main()
{
    int A[5]={1,2,3,4,5};
    fun(A,5);
    cout<<"Value of A[4] :"<<A[4]<<endl;
    fun1(A,5);
    cout<<"Value of A[4] :"<<A[4]<<endl;
    return 0;
}