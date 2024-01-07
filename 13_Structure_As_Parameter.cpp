#include<iostream>
using namespace std;
struct Rectangle 
{
    int length;
    int breadth;
};

int AreaByValue(struct Rectangle r1)
{
    return r1.length*r1.breadth;    
}

int AreaByReference(struct Rectangle &r1)
{
    r1.length=20;
    return r1.length*r1.breadth;    
}

int AreaByPointer(struct Rectangle *r1)
{
    r1->length=30;
    return r1->length*r1->breadth;    
}
int main()
{   
    struct Rectangle r={10,20};
    cout<<"Area :"<<AreaByValue(r)<<endl;    
    cout<<"Area :"<<AreaByReference(r)<<endl;
    cout<<"L*B : "<<r.length<<"*"<<r.breadth<<endl;
    cout<<"Area :"<<AreaByPointer(&r)<<endl;
    cout<<"L*B : "<<r.length<<"*"<<r.breadth<<endl;
    return 0;
}