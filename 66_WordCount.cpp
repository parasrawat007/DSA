#include<iostream>
using namespace std;

int main()
{
    char A[] = "How Are  You";
    int count = 1;

    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i]==' '&&A[i-1]!=' ')
            count++;
    }

    cout << "words : " << count << endl;
    return 0;
}