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
        m->A[m->n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
}

int Get(struct Matrix m,int i, int j)
{
    if(i>=j)
        return m.A[m.n*(j-1)-(j-2)*(j-1)/2+i-j];
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
                cout<<m.A[m.n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
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
        for (int j = i; j <=m.n; j++)
        {
                cout<<"Enter element for A["<<  j <<"]"<< "["<<i <<"] :: " ;
                cin>>e;
                Set(&m,j,i,e);
        }
    }
    
    Display(m);
    return 0;
}