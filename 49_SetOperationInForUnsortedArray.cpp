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
    cout << endl
         << "Elements are :: ";
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
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    return x;
}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
            return i;
    }
    return -1;
}

int LinearSearchTranspose(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            Swap(&arr->A[i], &arr->A[i - 1]);
            return i - 1;
        }
    }
    return -1;
}
int LinearSearchMoveToFront(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            Swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;

        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
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

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int s = 0;
    for (int i = 0; i < arr.length; i++)
        s = s + arr.A[i];
    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array *arr)
{
    int *B = new int[arr->length];

    for (int i = 0, j = arr->length - 1; i < arr->length; i++, j--)
        B[j] = arr->A[i];

    for (int i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}
void Reverse2(struct Array *arr)
{
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
        Swap(&arr->A[i], &arr->A[j]);
}
void InsertSort(struct Array *arr, int x)
{
    if (arr->length == arr->size)
        return;
    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}
int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}
void ReArrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            Swap(&arr->A[i], &arr->A[j]);
    }
}
struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->length + arr2->length;
    return arr3;
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = arr1->length + arr2->length;
    return arr3;
}

struct Array *InterSection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = arr1->length + arr2->length;
    return arr3;
}

struct Array *Diffrence(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
    arr3->size = arr1->length + arr2->length;
    return arr3;
}

struct Array *UnsortedUnion(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    for (int i = 0; i < arr1->length; i++)
    {
        arr3->A[i] = arr1->A[i];
        arr3->length++;
    }
    for (int i = 0; i < arr1->length; i++)
    {
        if (LinearSearch(*arr2, arr1->A[i]) < 0)
            arr3->A[arr3->length++] = arr2->A[i];
    }
    return arr3;
}

struct Array *UnsortedIntersection(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    for (int i = 0; i < arr1->length; i++)
    {
        if (LinearSearch(*arr2, arr1->A[i]) >= 0)
            arr3->A[arr3->length++] = arr1->A[i];
    }
    return arr3;
}

struct Array *UnsortedDiffrence(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    for (int i = 0; i < arr1->length; i++)
    {
        if (LinearSearch(*arr2, arr1->A[i]) < 0)
            arr3->A[arr3->length++] = arr1->A[i];
    }
    return arr3;
}

int main()
{
    struct Array arr1 = {{25, 2, 15, 6, 10}, 10, 5};
    struct Array arr2 = {{20, 15, 3, 6, 7}, 10, 5};

    struct Array *arr3 = UnsortedUnion(&arr1, &arr2);
    struct Array *arr4 = UnsortedIntersection(&arr1, &arr2);
    struct Array *arr5 = UnsortedDiffrence(&arr1, &arr2);

    Display(*arr3);
    Display(*arr4);
    Display(*arr5);
    return 0;
}