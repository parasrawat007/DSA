#include<iostream>
using namespace std;

int main()
{
    int a=10;
    int *p;
    p=&a;
    cout<<"Value Pointed by p : "<<*p<<endl
    <<"Value of p : "<<p<<endl
    <<"Address of a : "<<&a<<endl
    <<"Address of p : "<<&p<<endl
    <<"Address of *p "<<&(*p);
    return 0;
}