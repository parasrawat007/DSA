#include <iostream>
using namespace std;

int main()
{
    int A[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int n = 10;

    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        if (A[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
            if(count>1)
                cout<<"Duplicate Element "<<A[i]<<" is present "<<count<<" times."<<endl;
        }
    }

    return 0;
}