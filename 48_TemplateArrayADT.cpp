#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
    T *A;
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
        A = new T[size];
    }
    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Insert(int index, T x);
    T Delete(int index);
};
template <class T>
void Array<T>::Display()
{
    cout << endl
         << "Elements are :: ";
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <class T>
void Array<T> ::Insert(int index, T x)
{
    if (index >= 0 && index < size)
    {
        for (int i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}
template <class T>
T Array<T> ::Delete(int index)
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

int main()
{
    Array<int> arr(10);
    arr.Insert(0,10);
    arr.Insert(1,20);
    arr.Insert(2,30);
    arr.Display();
    cout<<"3rd element deleted at index 2 :: "<<arr.Delete(2);
    arr.Display();

    return 0;
}