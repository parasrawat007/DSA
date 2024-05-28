#include<iostream>
//#include <bitset>
using namespace std;

int main()
{
    char A[]="finding";
    int x=0,h=0;

    for (int i = 0; A[i]!='\0'; i++)
    {
        x=1;
        x=x<<A[i]-97;
        //cout<<bitset<32>(x&h)<<endl;

        if((x&h)>0)
        {
            cout<<"repeat "<<A[i]<<endl;
        }
        else
        {
            h=h|x;
        }
    }
    
    return 0;
}