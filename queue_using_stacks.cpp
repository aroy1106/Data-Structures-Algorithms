#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s1;
    int x;

    cin>>x;

    s1.push(x);
    s1.push(x+1);
    s1.push(x+2);
    s1.push(x+3);
    s1.push(x+4);
    cout<<s1.top()<<endl;

    return 0;
}