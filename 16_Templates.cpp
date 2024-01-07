#include<iostream>
using namespace std;
template <class T>
class Arithmatic
{
    private:
    T a;
    T b;
    public:
    Arithmatic(T a,T b);
    T Add();
    T Substract();
};

int main()

{
    Arithmatic<int> a(10,20);
    cout<<"Add :"<<a.Add()<<endl;
    cout<<"Substract :"<<a.Substract()<<endl;

    Arithmatic<float> b(10.2,20.3);
    cout<<"Add :"<<b.Add()<<endl;
    cout<<"Substract :"<<b.Substract()<<endl;
    return 0;
}

template <class T>
Arithmatic<T>::Arithmatic(T a, T b)
{
    this->a=a;
    this->b=b;
}
template <class T>
T Arithmatic<T>::Add()
{
    return a+b;
}

template <class T>
T Arithmatic<T>::Substract()
{
    return a-b;
}
