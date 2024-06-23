#include <iostream>
using namespace std;

class ToeplitzMatrix
{
private:
    int *A;
    int n;

public:
    ToeplitzMatrix()
    {
        n = 2;
        A = new int[2*n-1];
    }

    ToeplitzMatrix(int n)
    {
        this->n = n;
        A = new int[2*n-1];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    int GetDimension();
    void Display();
};

void ToeplitzMatrix ::Set(int i, int j, int x)
{
    if(i<=j)
        A[j-i]=x;
    else
        A[n+i-j-1]=x;
}

int ToeplitzMatrix ::Get(int i, int j)
{
   if(i<=j)
        return A[j-i];
    else
       return A[n+i-j-1];
}

void ToeplitzMatrix::Display()
{
    cout<<"Array ::"<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i<=j)
                cout<<A[j-i]<<" ";
            else
                cout<<A[n+i-j-1]<<" ";     
        }
        cout << endl;      
        
    }
    
}

int ToeplitzMatrix::GetDimension()
{
    return n;
}

int main()
{
    int d;
    cout<<"Enter Dimension :: ";
    cin>>d;

    ToeplitzMatrix t(d);
    int x;

    for (int i = 1; i <=d; i++)
    {
        for (int j = 1; j <=d; j++)
        {            
            cin>>x;
            t.Set(i,j,x);
        }
        
    }
    t.Display();
    cout<<"Element At A[2][2] ::"<<t.Get(2,1);
    return 0;
}