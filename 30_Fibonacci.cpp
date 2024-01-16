#include <iostream>
using namespace std;
int fib(int n)
{
    int t0=0,t1=1,s=0;
    if(n<=1)
    {
        return n;
    }
    for (int i = 2; i <= n; i++)
    {
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
    
}
int fibr(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibr(n - 2) + fib(n - 1);
}
int F[10]={-1};

int fibm(int n)
{       
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 1] == -1)
            F[n - 1] = fibm(n - 1);
            
        if (F[n - 2] == -1)
            F[n - 2] = fibm(n - 2);

        F[n] = F[n - 2] + F[n - 1];
        return F[n];
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
       F[i]=-1;
    }    
    cout << "Fib 5 :: " << fib(7) << endl;
    cout << "Fib 5 :: " << fibr(7) << endl;
    cout << "Fib 5 :: " << fibm(7) << endl;
    return 0;
}