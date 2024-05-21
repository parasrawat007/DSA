#include <iostream>
using namespace std;

int max(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int min(int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

int main()
{
    int A[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int n = 10;
    int k = 10;
    int l = min(A, n);
    int h = max(A, n) + 1;

    int *H = new int[h];
    for (int i = 0; i < h; i++)
    {
        H[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (H[k - A[i]] != 0 && k - A[i] > 0)
        {
            cout << A[i] << " + " << k - A[i] << " = " << k << endl;
        }
        H[A[i]]++;
    }

    return 0;
}