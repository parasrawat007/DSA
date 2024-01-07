#include<iostream>

using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};
void initialize(struct Rectangle *r, int l,int b)
{
    r->length=l;
    r->breadth=b;
}
int area(struct Rectangle r)
{
    return r.length*r.breadth;
}
void changelength(struct Rectangle *r,int l)
{
    r->length=l;
}
int main()
{
    struct Rectangle r;
    
    initialize(&r,10,20);
    changelength(&r,30);
    cout<<"Area : "<<area(r);
    
    return 0;
}