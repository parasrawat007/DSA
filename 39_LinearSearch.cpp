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
int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};

    Display(arr);
    cout<<endl;
    cout<<"Search of Element 5 :: "<<LinearSearch(arr,5)<<endl;
    cout<<endl;

    cout<<"Search of Element 5 :: "<<LinearSearchTranspose(&arr,5);
    Display(arr);
    cout<<endl<<endl;

    cout<<"Search of Element 5 :: "<<LinearSearchMoveToFront(&arr,5);
    Display(arr);
    return 0;
}