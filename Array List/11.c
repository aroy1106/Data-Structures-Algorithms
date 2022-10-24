#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int* data;
    int size;
}arraylist;

int search(arraylist P, int position)
{
    int i;
    if(position > P.size)
        return 1;
    else
        return P.data[position-1];
}
int main()
{
    arraylist L;
    L.size = 0;
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    L.data = malloc(n*sizeof(int));

    for(i = 0 ; i < n ; i++)
    {
        printf("Enter the value: ");
        scanf("%d",&L.data[i]);
        L.size++;
    }
    
    int pos;
    printf("Enter the position you want to find the element of: ");
    scanf("%d",&pos);

    int result = search(L,pos);

    if(result == 1)
        printf("Position out of range\n");
    else
        printf("Element present at %d location is %d",pos,result);

    return 0;
}
