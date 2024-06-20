#include <iostream>
using namespace std;

class LowerTri
{
private:
    int *A;
    int n;

public:
    LowerTri()
    {
        n = 2;
        A = new int[n * (n + 1) / 2];
    }

    LowerTri(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    int GetDimension();
    void Display();
};

void LowerTri ::Set(int i, int j, int x)
{
    if (i >= j)
    {
        A[i * (i - 1) / 2 + j - 1] = x;
    }
}

int LowerTri ::Get(int i, int j)
{
    if (i >= j)
    {
        return A[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}

void LowerTri::Display()
{
    cout<<"Array ::"<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << A[i * (i - 1) / 2 + j - 1] << " ";
        }
        cout << endl;
    }
}

int LowerTri::GetDimension()
{
    return n;
}

int main()
{
    int d;
    cout<<"Enter Dimension :: ";
    cin>>d;

    LowerTri t(d);
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
    cout<<"Element At A[2][2] ::"<<t.Get(2,2);
    return 0;
}