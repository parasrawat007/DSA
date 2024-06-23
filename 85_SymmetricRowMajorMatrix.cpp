#include <iostream>
using namespace std;

class SymmetricMatrix
{
private:
    int *A;
    int n;

public:
    SymmetricMatrix()
    {
        n = 2;
        A = new int[n * (n + 1) / 2];
    }

    SymmetricMatrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    int GetDimension();
    void Display();
};

void SymmetricMatrix ::Set(int i, int j, int x)
{
    if (i >= j)
        A[i*(i-1)/2+j-1] = x;
}

int SymmetricMatrix ::Get(int i, int j)
{
    if (i >= j)
    {
        return A[i*(i-1)/2+j-1];
    }
    return A[j*(j-1)/2+i-1];
}

void SymmetricMatrix::Display()
{
    cout<<"Array ::"<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i>=j)
                cout << A[i*(i-1)/2+j-1] << " ";
            else
                cout << A[j*(j-1)/2+i-1] << " ";
        }
        cout << endl;
    }
    
}

int SymmetricMatrix::GetDimension()
{
    return n;
}

int main()
{
    int d;
    cout<<"Enter Dimension :: ";
    cin>>d;

    SymmetricMatrix t(d);
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