#include<iostream>
using namespace std;

int main()
{
    int a=10;
    int &b=a;
    cout<<"Value of a :"<<a<<endl;
    cout<<"Value of b :"<<b<<endl;
    ++b;
    cout<<"Value of a :"<<a<<endl;
    cout<<"Value of b :"<<b<<endl;
    cout<<"Address of a :"<<&a<<endl;
    cout<<"Address of b :"<<&b<<endl;
    
    return 0;
}