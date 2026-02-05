#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n)
{
    struct Node *t,*last;
    Head=(struct Node*) malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;

    last=Head;
    for (int i = 1; i < n; i++)
    {
        t=(struct Node*) malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *h)
{
    do
    {
        cout<<h->data<<"->";
        h=h->next;
    } while (h!=Head);
    
}
void RDisplay(struct Node *h)
{
    static int f=0;
    if(h!=Head||f==0)
    {
        f=1;
        cout<<h->data<<"->";
        RDisplay(h->next);
    }
    f=0;
}
int Length(struct Node *p)
{
    int i=0;
    do
    {
        ++i;
        p=p->next;
    }
    while(p!=Head);
    return i;    
}

void Insert(struct Node *p,int index,int x)
{
    struct Node *t=(struct Node*) malloc(sizeof(struct Node *));
    t->data=x;
    if(index<0||index>Length(p))
        return;
    if(index==0)
    {
        if(Head==NULL)
        {
            t->next=t;
            Head=t;
        }
        else
        {
            while(p->next!=Head)
            {
                p=p->next;
            }
            p->next=t;
            t->next=Head;
            Head=t;
        }
    }
    else
    {
        for (int i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;        
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *t;
    int x;
    if(index <1 || index> Length(p))
        return -1;
    
    if(index==1)
    {
        while(p->next!=Head)
        {
            p=p->next;
        }
        x=Head->data;
        if(Head==p)
        {
            delete Head;
            Head=NULL;
        }
        else
        {
            p->next =Head->next;
            delete Head;
            Head=p->next;
        }
        return x;
    }
    else
    {
        for (int i = 0; i < index-2; i++)
        {
            p=p->next;
        }
        t=p->next;
        
        p->next=t->next;
        x=t->data;
        delete t;
    }
}

int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    // Insert(Head,2,11);
    // Insert(Head,0,11);
    // Insert(Head,5,11);
    Delete(Head,1);
    Delete(Head,2);
    Delete(Head,5);
    Display(Head);
    //RDisplay(Head);
    return 0;
}