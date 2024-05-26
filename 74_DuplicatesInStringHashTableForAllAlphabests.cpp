#include<iostream>
using namespace std;

int main()
{
    char A[]="FIndIng";
    int H[52]={0};
    
    for (int i = 0; A[i]!='\0' ; i++)
    {
        if(A[i]>=97)
            H[A[i]-97]++;
        else
            H[A[i]-65+26]++;
    }
    
    for (int i = 0; i < 52; i++)
    {
        if(H[i]>1&&i<26)
            cout<<(char)(i+97)<<" Occurs "<<H[i]<<" times."<<endl;
        else if(H[i]>1&&i>26)
            cout<<(char)(i+65-26)<<" Occurs "<<H[i]<<" times."<<endl;
    }
    
    return 0;
}