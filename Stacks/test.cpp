#include<iostream>
using namespace std;

void fun(int x, int* y, int &z)
{
    x = *y; 
    
    z = *y + x;

    *y = x; 
}

int main()
{
    int a = 10, b = 20, c = 30;
    fun(a,&b,c);

    cout<<a<<" "<<b<<" "<<c<<endl;

    return 0;
}