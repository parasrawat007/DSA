#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first,*last,*second,*third;

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
void Create2(int a[], int n)
{
    Node *t,*last;
    second =(struct Node*) malloc(sizeof(Node));
    second->data=a[0];
    second->next=NULL;
    last=second;

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
struct Node* LSearch(struct Node* p,int key)
{
    while(p!=NULL)
    {
        if(p->data==key)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
struct Node* RSearch(struct Node* p,int key)
{
    if(p==NULL)
        return NULL;
    if(p->data==key)
    return p;
    RSearch(p->next, key);
}
struct Node* ImporvedSearch(struct Node* p,int key)   //Move key to head
{
    struct Node* q=NULL;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            if (q != NULL) // key not in first node
            {
                q->next=p->next;
                p->next=first;
                first=p;
            }
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node* t;
    if(index <0 || index >Count(p))
        return;
    t=(struct Node *) malloc(sizeof(struct Node*));
    t->data=x;
    if(index==0)
    {
        t->next=first;
        first=t;
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

void InsertLast(int x)
{
    struct Node* t;
    t=(struct Node*) malloc(sizeof(struct Node*));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=last=t;
    }
    else
    {
        last->next=t;
        last=t;
    }

}
void InsertSorted(struct Node* p,int x)
{
    struct Node* q=NULL;
    struct Node* t=(struct Node*) malloc(sizeof(struct Node*));
    t->data=x;
    if(first==NULL)
        first=t;
    else
    {
        while (p && p->data<x)
        {        
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;  
        }
    }
}

int Delete(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1;
    if(index<0 || index >Count(p))
        return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    for (int i = 0; i < index-1; i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    x=p->data;
    free(p);
    return x;
}

int isSorted(struct Node *p)
{
    int x=-65536;
    while(p!=NULL)
    {
        if(p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
             p->next=q->next;
            free(q);
            q=p->next;           
        }

    }
}
void Reverse1(struct Node *p)
{
    int *A;
    int i=0;
    struct Node *q;
    A=(int*) malloc(sizeof(int)*Count(p));
    q=p;
    while (q!=NULL)
    {
        A[i++]=q->data;
        q=q->next;
    }
    q=p;
    --i;
    while (q!=NULL)
    {
        q->data=A[i--];
        q=q->next;
    }
    
}
void Reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void Concat(struct Node *p,struct Node *q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}
void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }

    while (p && q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        
        }
    }
    if(p) last->next=p;
    if(q) last->next=q;


}
int isLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=first;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    } while (p && q && p!=q);
    
    if(p==q)
        return 1;
    else 
        return 0;
}
int main()
{
    int a[]={10,20,30,40,50};
    // int b[]={5,15,25,35,45};
    
    Create(a,5);

    struct Node *t1,*t2;
    t1=t2=first;
    t1=first->next->next->next;
    t2=first->next->next->next;
    t2->next=t1;
    cout<<isLoop(first);

    // Create(a,5);
    // Create2(b,5);
    // Merge(first,second);
    
    // Create(a,5);
    // Create2(b,5);
    // Concat(first,second);
    
    // Reverse1(first);
    //Reverse2(first);
    // RemoveDuplicate(first);
    // if(isSorted(first))
    // {
    //     cout<<"Sorted";
    // }
    // else
    // {
    //     cout<<"Not Sorted";
    // }
    // Delete(first,2);
    //RReverseDisplay(first);    
    //cout<<"Count :: "<<RMax(first);  
    //Node* p= LSearch(first,8);
    // Node* p= ImporvedSearch(first,1);
    // if(p==NULL)
    //     cout<<"Not Found";
    // else
    //     cout<<"Found ";
    // Insert(first,0,1);
    // Insert(first,1,2);
    // Insert(first,2,3);
    // Insert(first,3,4);
    // InsertLast(1);
    // InsertLast(2);
    // InsertLast(3);
    // InsertLast(0);
  // InsertSorted(first,0);
    // InsertSorted(first,3);
    // InsertSorted(first,6);
    // Display(first);
    // Your code here
    return 0;
}