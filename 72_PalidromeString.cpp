#include <iostream>
using namespace std;
int strcmpi(char A[], char B[])
{
    int i, j;
    for (i = 0, j = 0; A[i] != '\0' || B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
            break;
    }

    if (A[i] == B[j])
    {
        return 0;
    }
    else if (A[i] < B[j])
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{

    char A[] = "madam";
    char B[6];

    int i, j, t;
    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i = i - 1;

    for (j = 0; i >= 0; j++, i--)
    {
        B[j] = A[i];
    }
    B[j] = '\0';

    if(strcmpi(A,B)==0)
        cout<<"Palidrome";
    else
        cout<<"Not Palidrome";
    return 0;
}