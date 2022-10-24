#include<iostream>
#include<climits>
using namespace std;

void filldata(int arr[], int x)
{
    cout<<"Enter data: ";
    for(int i = 0 ; i < x ; i++)
        cin>>arr[i];
    
}
void display(int arr[], int x)
{
    cout<<"The array is: ";
    for(int i = 0 ; i < x ; i++)
        cout<<arr[i]<<" ";
}
void minmax(int arr[], int x)
{
    int minimum = INT_MAX;
    int maximum = INT_MIN;

    for(int i = 0 ; i < x ; i++)
    {
        minimum = min(minimum,arr[i]);
        maximum = max(maximum,arr[i]);
    }
    cout<<"\nThe maximum and minimum element of the array is: "<<maximum<<" and "<<minimum<<endl;
}
int main()
{
    int n;

    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];

    filldata(arr,n);
    display(arr,n);
    minmax(arr,n);
    
    return 0;
}