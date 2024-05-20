#include<iostream>
using namespace std;

int max(int a[],int n)
{
    int max=a[0];
    for (int i = 1; i < n; i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;    
}

int min(int a[],int n)
{
    int min=a[0];
    for (int i = 1; i < n; i++)
    {
        if(a[i]<min)
            min=a[i];
    }
    return min;    
}

int main()
{
    int A[10]={3,6,8,8,10,12,15,15,15,20};
    
    int n=10;
    int l=min(A,n);
    int h=max(A,n);

    int *H= new int[h];

    for (int i = 0; i < h; i++)
    {
        H[i]=0;
    }
    

    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }
    
    for (int i = l; i < h; i++)
    {
        if(H[i]>1)
            cout<<i<<" Repeats "<<H[i]<<" times."<<endl;
    }
    
    return 0;
}