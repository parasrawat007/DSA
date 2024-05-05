#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int size)
    {
        this->size = size;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    void Swap(int *x, int *y);
    int LinearSearch(int key);
    int LinearSearchTranspose(int key);
    int LinearSearchMoveToFront(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void ReArrange();
    Array *Merge(Array arr2);
    Array *Union(Array arr2);
    Array *InterSection(Array arr2);
    Array *Diffrence(Array arr2);
    Array *UnsortedUnion(Array arr2);
    Array *UnsortedIntersection(Array arr2);
    Array *UnsortedDiffrence(Array arr2);
};

void Array::Display()
{
    cout << endl
         << "Elements are :: ";
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Array ::Append(int x)
{
    if (length < size)
        A[length++] = x;
}

void Array ::Insert(int index, int x)
{
    if (index >= 0 && index < size)
    {
        for (int i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

int Array ::Delete(int index)
{
    int x = 0;
    if (index >= 0 && index < length)
    {
        x = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
    return x;
}

void Array ::Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array ::LinearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
            return i;
    }
    return -1;
}

int Array ::LinearSearchTranspose(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            Swap(&A[i], &A[i - 1]);
            return i - 1;
        }
    }
    return -1;
}

int Array ::LinearSearchMoveToFront(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            Swap(&A[i], &A[0]);
            return 0;
        }
    }
    return -1;
}

int Array ::BinarySearch(int key)
{
    int l, mid, h;
    l = 0;
    h = length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;

        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinarySearch(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinarySearch(a, l, mid - 1, key);
        else
            return RBinarySearch(a, mid + 1, h, key);
    }
    return -1;
}

int Array ::Get(int index)
{
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

void Array ::Set(int index, int x)
{
    if (index >= 0 && index < length)
        A[index] = x;
}

int Array ::Max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

int Array ::Min()
{
    int min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

int Array ::Sum()
{
    int s = 0;
    for (int i = 0; i < length; i++)
        s = s + A[i];
    return s;
}

float Array ::Avg()
{
    return (float)Sum() / length;
}

void Array ::Reverse()
{
    int *B = new int[length];

    for (int i = 0, j = length - 1; i < length; i++, j--)
        B[j] = A[i];

    for (int i = 0; i < length; i++)
        A[i] = B[i];
}

void Array ::Reverse2()
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
        Swap(&A[i], &A[j]);
}

void Array ::InsertSort(int x)
{
    if (length == size)
        return;
    int i = length - 1;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

int Array ::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}

void Array ::ReArrange()
{
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        if (i < j)
            Swap(&A[i], &A[j]);
    }
}

Array *Array ::Merge(Array arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = length + arr2.length;
    arr3->size = length + arr2.length;
    return arr3;
}

Array *Array ::Union(Array arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr3->A[k++] = arr2.A[j++];
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = k;
    arr3->size = length + arr2.length;
    return arr3;
}

Array *Array ::InterSection(Array arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < A[i])
            j++;
        else if (A[i] == arr2.A[j])
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = length + arr2.length;
    return arr3;
}

Array *Array ::Diffrence(Array arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }

    arr3->length = k;
    arr3->size = length + arr2.length;
    return arr3;
}

Array *Array ::UnsortedUnion(Array arr2)
{
    Array *arr3 = new Array(length + arr2.length);
    for (int i = 0; i < length; i++)
    {
        arr3->A[i] = A[i];
        arr3->length++;
    }
    for (int i = 0; i < length; i++)
    {
        if (arr2.LinearSearch(A[i]) < 0)
            arr3->A[arr3->length++] = arr2.A[i];
    }
    return arr3;
}

Array *Array ::UnsortedIntersection(Array arr2)
{
    Array *arr3 = new Array(length + arr2.length);

    for (int i = 0; i < length; i++)
    {
        if (arr2.LinearSearch(A[i]) >= 0)
            arr3->A[arr3->length++] = A[i];
    }
    return arr3;
}

Array *Array ::UnsortedDiffrence(Array arr2)
{
    Array *arr3 = new Array(length + arr2.length);

    for (int i = 0; i < length; i++)
    {
        if (arr2.LinearSearch(A[i]) < 0)
            arr3->A[arr3->length++] = A[i];
    }
    return arr3;
}

int main()
{
    int ch, x, index, size;
    Array *arr;

    cout << "Enter size of Array :: ";
    cin >> size;
    arr = new Array(size);
    do
    {
        cout << "Menue" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Serach" << endl;
        cout << "4.Sum" << endl;
        cout << "5.Display" << endl;
        cout << "6.Exit" << endl;

        cout << "Enter your choice :: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter an Element and Index :: ";
            cin >> x >> index;
            arr->Insert(index, x);
            break;
        case 2:
            cout << "Enter index :: ";
            cin >> index;
            arr->Delete(index);
            break;
        case 3:
            cout << "Enter Search :: ";
            cin >> x;
            index = arr->LinearSearch(x);
            cout << "Element " << x << " is at index " << index << "." << endl;
            break;
        case 4:
            cout << "Sum of elements :: " << arr->Sum() << endl;
            break;
        case 5:
            arr->Display();
        }
    } while (ch < 6);

    return 0;
}