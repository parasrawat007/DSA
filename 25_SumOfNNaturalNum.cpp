#include<iostream>
using namespace std;
int sum(int n)
{
    if(n==0)
    {
        return n;
    }
    else
    {
        return sum(n-1)+n;
    }
}
int Isum(int n)
{
    int s=0;
    for (int i = 1; i <=n; i++)
    {
        s=s+i;
    }
    return s;   
}
int Fsum(int n)
{
    return n*(n+1)/2;
}
int main()
{
    int a=5;
    cout<<"Recursive Sum :: "<<sum(a)<<endl;
    cout<<"Itrative Sum :: "<<Isum(a)<<endl;
    cout<<"Formula Sum :: "<<Fsum(a)<<endl;
    return 0;
}