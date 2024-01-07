#include<iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r;
    struct Rectangle r1={10,5};
    cout<<"area of rectangle "<<r1.length*r1.breadth;
    return 0;
}