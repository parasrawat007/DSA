#include <iostream>
using namespace std;

int valid(char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!(name[i] >= 65 && name[i] <= 90) && !(name[i] >= 90 && name[i] <= 122) && !(name[i] >= 48 && name[i] <= 57))
            return 0;
    }
    return 1;
}

int main()
{
    char name[] = "Anil?123";

    if(valid(name))
        cout<<"Valid";
    else
        cout<<"Invalid";

    return 0;
}