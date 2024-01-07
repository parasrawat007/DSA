#include<iostream>
using namespace std;
int* fun(int n)
{
    int *p;
    p= (int *)malloc(sizeof(int)*5);
    return p;
}
int main()
{
    int *p;
    p=fun(5);
    cout<<"Memory allocated successfuly ";
    return 0;
}
