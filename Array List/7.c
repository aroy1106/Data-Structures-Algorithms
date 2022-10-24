#include<stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];

    printf("Enter the elements: ");
    int i;
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    
    int sum, count = 0;
    printf("Enter a sum: ");
    scanf("%d",&sum);
    
    for (i = 0; i < n; i++)
    {
        if(sum == a[i] + a[i+1])
            count++;
    }
    
    printf("%d",count);   
    
    return 0;
}
