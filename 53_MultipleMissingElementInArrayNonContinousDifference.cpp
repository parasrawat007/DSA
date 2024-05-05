/*
    Array = {6,7,8,9,10,11,13,14,15,16,17}
    find missing element
*/

#include<iostream>
using namespace std;

int main()
{

    int a[]= {6,7,8,9,11,12,15,16,17,18,19};
    int diff=a[0]-0;

    for (int i = 0; i < 11; i++)
    {
        if(a[i]-i != diff)
        {
            while (diff<a[i]-i)
            {
                 cout<<"Missing Element :: "<<i+diff<<" "<<endl;
                 diff++;
            }
        }
    }
    

    return 0;
}