#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p;
    double *q = (double *)malloc(sizeof(double)*10);
    p = (int *)malloc(sizeof(int)*10);//malloc return the first memory address of byte allocating n byte in memory where n is the input of malloc
    //it should be type casted to its respected data type
        *(p+5) = 7;
    *(p+1) = 73;
    *(p+3) = 72;
    for(int i=1; i<7; i+=2)
        printf("*(p+%d) = %d\n", i, *(p+i));
    return 0;
   }