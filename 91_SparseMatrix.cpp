#include<iostream>
using namespace std;

class Element
{
    public:
        int i,j,x;
};

class Sparse
{
    private:
    int m,n,num;
    Element *e;
    
    public:
    Sparse(int m, int n, int num)
    {
        this->m=m;
        this->n=n;
        this->num=num;
        e=new Element[num];
    }
    
    ~Sparse()
    {
        delete []e;
    }
    Sparse operator+(Sparse &s);
   

    friend istream & operator >>(istream &is,Sparse &s);
    friend ostream & operator <<(ostream &os,Sparse &s); 
};
Sparse Sparse:: operator+(Sparse &s)
{
    if(m!=s.m||n!=s.n)
            return Sparse(0,0,0); 
    Sparse *sum = new Sparse(s.m,s.n,(s.m+m)*(s.n+n));
    int i,j,k;
    i=j=k=0;
    while(i<num&&j<s.num)
    {
        if(e[i].i<s.e[j].i)
        {
            sum->e[k++]=e[i++];
        }
        else if(e[i].i>s.e[j].i)
        {
            sum->e[k++]=s.e[j++];
        }
        else
        {
            if(e[i].j<s.e[j].j)
            {
                sum->e[k++]=e[i++];
            }
            else if(e[i].j>s.e[j].j)
            {
                sum->e[k++]=s.e[j++];
            }
            else
            {
                sum->e[k]=e[i++];
                sum->e[k++].x +=s.e[j++].x;
            }
        }
    }

    for (; i < this->num; i++)
        sum->e[k++]=e[i];

    for (; j < s.num; j++)
        sum->e[k++]=s.e[j];
    sum->num=k;
    return *sum;
        
}
istream & operator >>(istream &is,Sparse &s)
{
        cout<<"Enter non zero elements :: "<<endl;
        for (int i = 0; i < s.num; i++)
        {
            cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
        }        
        return is;
}
ostream & operator <<(ostream &os,Sparse &s)
{
    int k=0;
    cout<<"Matrix ::"<<endl;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if(s.e[k].i==i&&s.e[k].j==j)
                cout<<s.e[k++].x<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }  
    return os;
}
int main()
{
    Sparse s(3,3,3),s1(3,3,3);
    cin>>s;
    cout<<s;
    cin>>s1;
    cout<<s1;
    Sparse sum=s+s1;
    cout<<sum;
    return 0;
}