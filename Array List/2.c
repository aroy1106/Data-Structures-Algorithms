#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int data[1];
    int size;
}arraylist;

int main()
{
    arraylist L;
    arraylist* b;
    b = &L;

    L.size = 0;
    b->data = malloc(20*sizeof(int));

    return 0;
}
