#include<iostream>
using namespace std;

int main()
{
    int A[10]={3,6,8,8,10,12,15,15,15,20};
    
    int n=10;
    int l=A[0];
    int h=A[9];

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