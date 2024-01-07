#include<iostream>
using namespace std;

int funA(int n);
int funB(int n);

int main()
{
    int a=20;
    funA(a);
    return 0;
}

int funA(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        funB(n-1);
    }
}

int funB(int n)
{
    if(n>1)
    {
        cout<<n<<" ";
        funA(n/2);
    }
}
