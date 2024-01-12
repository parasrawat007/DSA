#include<iostream>
using namespace std;

double taylor(double x,double n)
{
    double s=1;
    while (n>0)
    {
        s=1+x/n*s;
        n--;
    }
    return s;
}
//Using Horner's Rule
double e(double x, double n)
{
    static double s=1;
    if(n==0)
        return s;
    s=1+x/n*s;
    return e(x,n-1);
}

int main()
{
    cout<<"Taylor :: "<<taylor(1,10)<<endl;
    cout<<"Taylor :: "<<e(1,10);
    return 0;
}