#include<iostream>

using namespace std;

class Rectangle 
{
    private:
        int length;
        int breadth;
    public:
        Rectangle(){length=breadth=1;}
        Rectangle(int l, int b);
        int area();
        int getLength(){return length;}
        void setlength(int l){length=l;}
        ~Rectangle();
        
};

int main()
{
    Rectangle r;
    cout<<"Area : "<<r.area()<<endl;
    r.setlength(33);
    cout<<"Length : "<<r.getLength()<<endl;

    return 0;
}

int Rectangle::area()
{
    return length*breadth;
}
Rectangle::Rectangle(int l, int b)
{
    length=l;
    breadth=b;
}
Rectangle::~Rectangle()
{
    cout<<"Destructor"<<endl;
}