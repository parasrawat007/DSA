#include<iostream>
using namespace std;
void swap(int x,int y)
{
    int temp=x;
    x=y;
    y=temp;
}

int main()
{
    //would swap because of call by value
    int a=10,b=20;
    cout<<"Swape Orignal A : "<<a<<" B : "<<b<<endl;
    swap(a,b);
    cout<<"Swape Result A : "<<a<<" B : "<<b<<endl;
    return 0;
}