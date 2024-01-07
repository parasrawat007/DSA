#include<iostream>
using namespace std;

int Factorial(int n)
{
    if(n<=0)
    {
        return 1;
    }
    else
    {
        return Factorial(n-1)*n;
    }
}
int IFactorial(int n)
{
    int f=1;
    for (int i = 1; i <= n; i++)
    {
        f=f*i;
    }
    return f;
}


int main()
{
    int a=5;
    cout<<"Recusrsive Factorial :: "<<Factorial(a)<<endl;
    cout<<"Itrative Factorial :: "<<IFactorial(a)<<endl;
    return 0;
}