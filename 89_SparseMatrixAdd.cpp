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

struct SparseMatrix* add(struct SparseMatrix *s1,struct SparseMatrix *s2)
{
    struct SparseMatrix *s3;
    int i,j,k;
    i=j=k=0;

    if(s1->m!=s2->m&&s1->n!=s2->n)
        return NULL;

    s3=new SparseMatrix;

    s3->m=s1->m;
    s3->n=s1->n;

    s3->element=(struct Element*)malloc(sizeof(struct Element)*(s1->num+s2->num));

    while (i<s1->num&&j<s2->num)
    {
        if(s1->element[i].i < s2->element[j].i)
            s3->element[k++]=s1->element[i++];
        else if(s1->element[i].i > s2->element[j].i)
            s3->element[k++]=s2->element[j++];
        else
        {
            if(s1->element[i].j < s2->element[j].j)
                s3->element[k++]=s1->element[i++];
            else if(s1->element[i].j > s2->element[j].j)
                s3->element[k++]=s2->element[j++];
            else
            {
                s3->element[k]=s1->element[i++];
                s3->element[k++].x+=s2->element[j++].x;
            }
        }
    }
    
    for(;i<s1->num;i++)
    s3->element[k++]=s1->element[i++];

    for(;j<s2->num;j++)
    s3->element[k++]=s2->element[j++];

    s3->num=k;
    return s3;    
}
int main()
{
    struct SparseMatrix s1,s2,*s3;

    cout<<"enter First matrix ::"<<endl;
    create(&s1);
    display(s1);

    cout<<"enter second matrix ::"<<endl;
    create(&s2);
    display(s2);

    cout<<"sum of matrix ::"<<endl;
    s3=add(&s1,&s2);
    display(*s3);

    return 0;
}