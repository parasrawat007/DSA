#include<iostream>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *term;
};

void create(struct Poly *p)
{
    cout<<"Enter number of terms ::";
    cin>>p->n;
    p->term=new Term[p->n];

    cout<<"Enter terms ::"<<endl;
    for (int i = 0; i < p->n; i++)
    {
        cin>>p->term[i].coeff>>p->term[i].exp;
    }
}

void Display(struct Poly p)
{
    for (int i = 0; i < p.n; i++)
    {
        cout<<p.term[i].coeff<<"x"<<p.term[i].exp<<"+";
    }
    cout<<endl;
}

struct Poly* add(struct Poly *p1,struct Poly *p2)
{
    int i,j,k;
    i=j=k=0;
   
    struct Poly *p3= new Poly;
    p3->term= new Term[p1->n+p2->n];

    while (i<p1->n&&j<p2->n)
    {
        if(p1->term[i].exp > p2->term[j].exp)
            p3->term[k++]=p1->term[i++];
        else if(p1->term[i].exp < p2->term[j].exp)
            p3->term[k++]=p2->term[j++];
        else 
        {
             p3->term[k]=p1->term[i++];
             p3->term[k++].coeff+=p2->term[j++].coeff;
        }
    }

    for (; i <p1->n; i++)
         p3->term[k++]=p1->term[i++];

    for (; j < p2->n; j++)
        p3->term[k++]=p2->term[j++];
    
    p3->n=k;

    return p3;    
} 

int main()
{
    Poly *p1= new Poly;
    Poly *p2= new Poly;
    Poly *p3;
    create(p1);
    Display(*p1);
   
    create(p2);
    Display(*p2);

    p3=add(p1,p2);
    Display(*p3);
    return 0;
}