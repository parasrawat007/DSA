#include<iostream>
using namespace std;

int main()
{
    int *p;
    p= (int *) malloc(5*sizeof(int));//c syntax
    p= new int[5];//c++ syntax
    cout<<"Memory Aloocated"<<endl;
    return 0;
}