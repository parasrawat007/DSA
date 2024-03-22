#include<iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    cout<<endl<<"Elements are :: ";
    for (int i = 0; i <arr.length; i++)
    {
        cout<<arr.A[i]<<" ";
    }
}

void Append(struct Array *arr,int x)
{
    if(arr->length < arr->size )
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr,int index,int x)
{
    if(index>=0&&index<arr->size)
    {
        for (int i = arr->length; i >index; i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}

int main()
{
    struct Array arr={{1,2,3,4,5},10,5};

    Append(&arr,6);   
    Display(arr);

    Insert(&arr,3,7);
    Display(arr);
    return 0;
}