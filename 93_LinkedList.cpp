#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first;

void Create(int a[], int n)
{
    Node *t,*last;
    first =(struct Node*) malloc(sizeof(Node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    for (int i = 1; i < n; i++)
    {
        t=(struct Node*) malloc(sizeof(Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


void Display(struct Node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}
void RDisplay(struct Node *n)
{
    if(n!=0)
    {
        cout<<n->data<<" ";
        RDisplay(n->next);
    }
}
void RReverseDisplay(struct Node *n)
{
    if(n!=0)
    {
        RReverseDisplay(n->next);
        cout<<n->data<<" ";
    }
}
int Count(struct Node *n)
{
    int i=0; 
    while(n!=NULL)
    {
        ++i;
        n=n->next;
    }
    return i;
}
int RCount(struct Node *n)
{
    if(n==0)
        return 0;
    return RCount(n->next)+1 ;
}
int Sum(struct Node *n)
{
    int sum=0; 
    while(n!=NULL)
    {
        sum=sum+n->data;
        n=n->next;
    }
    return sum;
}
int RSum(struct Node *n)
{
    if(n==0)
        return 0;
    return RSum(n->next)+n->data ;
}

int Max(struct Node *n)
{
    int max=INT32_MIN; 
    while(n!=NULL)
    {
        if(n->data>max)
            max=n->data;
        n=n->next;
    }
    return max;
}
int RMax(struct Node *n)
{
    if(n==0)
        return INT32_MIN;
    int x= RMax(n->next);
    return x>n->data?x:n->data;
}
int main()
{
    int a[]={1,2,3,4,5};
    Create(a,5);
    //RReverseDisplay(first);    
    cout<<"Count :: "<<RMax(first);  
    // Your code here
    return 0;
}