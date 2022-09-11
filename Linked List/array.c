#include<stdio.h>


void f(int a[], int b[], int m, int n)
{
    int i;
    for(i = 0 ; b[i] != 0 ; i++);
    
    int k = 0;
    for(int j = i ; j < n ; j++)
    {
        b[j] = a[k];
        k++;
    }
    for(i = 0 ; i < n ; i++)
    {
        printf("%d ",b[i]);
    }
}
int main()
{
    int x, y;
    printf("Enter no of elements in first: ");
    scanf("%d",&x);
    int a[x];

    printf("Enter no of elements in second: ");
    scanf("%d",&y);
    int b[y];

    for(int i = 0 ; i < x ; i++)
    {
        printf("Enter value in sorted manner: ");
        scanf("%d",&a[i]);
    }
    for(int i = 0 ; i < 2 ; i++)
    {
        printf("Enter value in sorted manner: ");
        scanf("%d",&b[i]);
    }
    b[2] = 0;
    b[3] = 0;
    b[4] = 0;

    f(a,b,x,y);

    return 0;
}