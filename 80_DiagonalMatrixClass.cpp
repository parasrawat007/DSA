#include<iostream>
using namespace std;

class Diagonal
{
    public:
        int n;
        int *A;

    Diagonal()
    {
        n=2;
        A=new int[n];
    }  
    Diagonal(int size)
    {
        n=size;
        A=new int[n];
    }
    void Set(int i, int j,int x);
    int Get(int i, int j);
    void Display();
    ~Diagonal()
    {
        delete []A;
    }
};
 
void Diagonal::Display()
{
        int i,j;
        for ( i = 0; i < n; i++)
        {
            for ( j = 0; j < n; j++)
            {
                if(i==j)
                    cout<<A[i]<<" ";
                else
                    cout<<0<<" ";
            }
            cout<<endl;
        }
}

void Diagonal:: Set(int i,int j,int x)
{
    if(i==j)
        A[i-1]=x;
}

int Diagonal::Get(int i,int j)
{
    if(i==j)
        return A[i-1];
    return 0;
}

int main()
{
    Diagonal d(3);
    d.Set(1,1,1);
    d.Set(2,2,2);
    d.Set(3,3,3);

    cout<<d.Get(3,3)<<endl;
    d.Display();
    return 0;
}