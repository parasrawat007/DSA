#include <iostream>
using namespace std;

class TriDiagonalMatrix
{
private:
    int *A;
    int n;

public:
    TriDiagonalMatrix()
    {
        n = 2;
        A = new int[3*n-2];
    }

    TriDiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[3*n-2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    int GetDimension();
    void Display();
};

void TriDiagonalMatrix ::Set(int i, int j, int x)
{
    if(i-j==1)
        A[j-1]=x;
    else if (i-j==0)
        A[n-1+j-1] = x;
    else if(i-j==-1)
        A[n-1+n+j-1]=x;
}

int TriDiagonalMatrix ::Get(int i, int j)
{
    if(i-j==1)
        return A[j-1];
    else if (i-j==0)
        return A[n-1+j-1];
    else if(i-j==-1)
        return A[n-1+n+j-1];
}

void TriDiagonalMatrix::Display()
{
    cout<<"Array ::"<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i-j==1)
                cout<<A[j-1]<<" ";
            else if (i-j==0)
                cout<<A[n-1+j-1]<<" ";
            else if(i-j==-1)
                cout<<A[n-1+n+j-1]<<" ";         
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    
}

int TriDiagonalMatrix::GetDimension()
{
    return n;
}

int main()
{
    int d;
    cout<<"Enter Dimension :: ";
    cin>>d;

    TriDiagonalMatrix t(d);
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