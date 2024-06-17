#include<iostream>
using namespace std;
struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m,int i, int j, int x)
{
    if(i>=j)
        m->A[i*(i-1)/2+j-1]=x;
}

int Get(struct Matrix m,int i, int j)
{
    if(i>=j)
        return m.A[i*(i-1)/2+j-1];
    else 
        return 0;
}

void Display(struct Matrix m)
{
    int i,j;
    for ( i = 1; i <= m.n; i++)
    {
        for ( j = 1; j <= m.n; j++)
        {
            if(i>=j)
                cout<<m.A[i*(i-1)/2+j-1]<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    struct Matrix m;
    cout<<"Enter Dimension Of Matrix :: ";
    cin>>m.n;
    int e;
    m.A=(int*) malloc( m.n*(m.n+1)/2*  sizeof(int));

    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <=m.n; j++)
        {
            if(i>=j)
            {
                cout<<"Enter element for A["<<  i <<"]"<< "["<<j <<"] :: " ;
                cin>>e;
                Set(&m,i,j,e);
            }
        }
    }

    Display(m);
    
    return 0;
}