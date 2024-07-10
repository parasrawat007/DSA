#include<iostream>
using namespace std;

struct Element 
{
    int i; 
    int j;
    int x;
};

struct SparseMatrix
{
    int m;
    int n;
    int num;
    struct Element *element;
};

void create(struct SparseMatrix *s)
{
    cout<<"Enter dimensions of matrix ::";
    cin>>s->m>>s->n;

    cout<<"Number of non-zero elements ::";
    cin>>s->num;

    s->element=(struct Element*)malloc(sizeof(struct Element)*s->num);

    cout<<"Enter elements of matrix ::"<<endl;
    for (int i = 0; i < s->num; i++)
    {
        cin>>s->element[i].i>>s->element[i].j>>s->element[i].x; 
    }
    
}
void display(struct SparseMatrix s)
{
    int k=0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if(s.element[k].i==i&&s.element[k].j==j)
            {
                cout<<s.element[k++].x<<" ";
            }
            else
                cout<<0<<" ";
        }        
        cout<<endl;
    }       
}

int main()
{
    struct SparseMatrix s;
    create(&s);
    display(s);
    return 0;
}