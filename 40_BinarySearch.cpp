#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    cout <<endl<< "Elements are :: ";
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->size)
    {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    if (index >= 0 && index < arr->length)
    {
        x=arr->A[index];
        for (int i = index; i < arr->length-1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    return x;
}

void Swap(int *x,int *y)
{
    int temp =*x;
    *x=*y;
    *y=temp;
}

int LinearSearch(struct Array arr,int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if(arr.A[i]==key)
            return i;
    }
    return -1;
}

int LinearSearchTranspose(struct Array *arr,int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if(arr->A[i]==key)
        {
            Swap(&arr->A[i],&arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}
int LinearSearchMoveToFront(struct Array *arr,int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if(arr->A[i]==key)
        {
            Swap(&arr->A[i],&arr->A[0]);
            return 0;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr,int key)
{
    int l, mid,h;
    l=0;
    h=arr.length-1;

    while (l<=h)
    {
        mid=(l+h)/2;
        
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else 
            l=mid+1;        
    }
    return -1;
}

int RBinarySearch(int a[],int l, int h, int key) 
{
    int mid;
    if (l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RBinarySearch(a,l,mid-1,key);
        else 
            return RBinarySearch(a,mid+1,h,key);
    }
    return -1;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};

    cout<<"Search of Element 5 :: "<<BinarySearch(arr,10)<<endl;
    cout<<"Search of Element 5 :: "<<RBinarySearch(arr.A,0,arr.length-1,3);
    Display(arr);
    return 0;
}