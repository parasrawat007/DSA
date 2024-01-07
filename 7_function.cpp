#include<iostream>

using namespace std;

//prototype/signature/declation
int add(int a, int b)//formal parameter
//defination of fuction
{
    return a+b;
}


int main()
{
    int x=10,y=20;
    cout<<"Sum of x & y : "<<add(x,y); //actual parameter
    return 0;
}