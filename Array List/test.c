#include<stdio.h>

int sum(char a[20],char b[20])
{
    int p, q;
    sscanf(a,"%d",&p);
    sscanf(b,"%d",&q);

    return p+q;
}
int main()
{
    char x[20] = "20";
    char y[20] = "80";

    printf("The sum of %s and %s is %d",x,y,sum(x,y));

    return 0;
}