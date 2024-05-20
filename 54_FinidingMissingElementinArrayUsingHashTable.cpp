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
    int a[10]={3,7,4,9,12,6,1,11,2,10};
    int n=10;
    int l= min(a,n);
    int h= max(a,n);
    int *t= new int[h];
    
    for (int i = 1; i < h; i++)
    {
       t[i]=0;
    }

    for (int i = 0; i <n; i++)
    {
        t[a[i]]++;
    }
    
    for (int i = l; i < h; i++)
    {
        if(t[i]==0)
        cout<<"Missing Elements :: "<<i <<endl;
    }
    
    return 0;
}