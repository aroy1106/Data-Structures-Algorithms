#include<stdio.h>

#define max 10

typedef struct
{
    int data[max];
    int size;
} arraylist;

int main()
{
    arraylist L;
    L.size = 0;
    int i;

    for (i = 0; i < max; i++)
    {
        printf("Enter the data in the array: ");
        scanf("%d",&L.data[i]);
        L.size++;
    }

    printf("The elements present in the array list are: ");
    for (i = 0; i < max; i++)
        printf("%d ",L.data[i]);
    printf("\nThe size of the array list is %d",L.size);
    
    return 0;
}