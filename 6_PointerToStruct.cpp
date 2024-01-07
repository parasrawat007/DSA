#include<iostream>
using namespace std;

struct Rectangle 
{
    int length;
    int breath;
};

int main()
{
    struct Rectangle r={10,20};
    struct Rectangle *p=&r;

    cout<<"Rectangle length : "<<(*p).length<<endl;
    cout<<"Rectangle length : "<<p->length<<endl;

    p= (struct Rectangle *) malloc(sizeof(struct Rectangle));
    p->length=20;
    cout<<"Rectangle length : "<<p->length;
    
    return 0;
}