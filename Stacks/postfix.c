#include<stdio.h>
#include<stdlib.h>

int main()
{
    char inf[] = "a+b-k*d-t/m";
    intopo(inf);
}

void intopo(char* in)
{
    int j = 0;
    char out[100];
    STACK s;
    init(&s);
    int i = 0; 

    while(in[i] != '\0')
    {
        if(isoperand(in[i]))
        {
            out[j++] = init[i];
        }
        else if(int [i] == '(')
        {
            push(&s,init[i]);
        }
    }
}