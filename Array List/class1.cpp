#include<iostream>
using namespace std;

int square(int p)
{
    return (p*p);
}

float square(float q)
{
    return (q*q);
}

int main()
{
    int a;
    float b;

    cout<<"Enter an integer value: ";
    cin>>a;
    cout<<"Enter a float value: ";
    cin>>b;

    cout<<"The square of "<<a<<" is "<<square(a)<<endl;
    cout<<"The square of "<<b<<" is "<<square(b)<<endl;

    return 0;
}  