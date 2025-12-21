#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

class LinkedList
{
    private:
        Node* first;
    public:
        LinkedList(){first = NULL;}
        LinkedList(int A[], int n);
        ~LinkedList();
        void Display();
        void Insert(int index, int x);  
        int Delete(int index);
        int Length();
};
LinkedList:: LinkedList(int A[], int n)
{
    Node *t ,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for (int i = 1; i < n; i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
LinkedList::~LinkedList()
{
    Node *p=first;
    while (first)
    {
        first=first->next;
        delete first;
        p=first;
    }
    
}
void LinkedList :: Display()
{
    Node *p=first;

    while (p)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
} 
int LinkedList::Length()
{
    Node *p=first;
    int i=0;
    while (p)
    {
        p=p->next;
        i++; 
    }
    return i;    
}
void LinkedList::Insert(int index, int x)
{
    Node *p=first,*t=new Node;
    if(index<0 || index>Length())
        return ;
    
    t->data=x;
    t->next=NULL;
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
int LinkedList::Delete(int index)
{
    int x;
    Node *p=first,*t;
    if(index<0||index>Length())
        return -1;
    if(index==0)
    {
        t=first;
        first=first->next;
        x=t->data;
        delete t;
    }
    for(int i=1;i<index-1;i++)
    {
        p=p->next;
    }
    t=p->next;
    x=t->data;
    p->next=t->next;
    delete t;
    return x;
}
int main()
{
    int A[]={1,2,3,4,5};
    LinkedList l(A,5); 
    l.Insert(0,45);
    l.Delete(0);
    l.Display();
    return 0;
}
