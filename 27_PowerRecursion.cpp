#include<iostream>
using namespace std;

int pow(int m ,int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return pow(m,n-1)*m;
    }
}

int pow1(int m ,int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n%2==0)
    {
        return pow(m*m,n/2);
    }
    else
    {
        return m*pow(m*m,(n-1)/2);
    }
}

int main()
{
    int m=3,n=4;
    cout<<m<<"pow"<<n<<" :: "<<pow(m,n)<<endl;
    cout<<m<<"pow"<<n<<" :: "<<pow1(m,n)<<endl;
    return 0;
}