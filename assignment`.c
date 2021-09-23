#include <stdio.h>
#include<math.h>


int main()
{
    float R, r;
    int n;
    scanf("%f %d", &R, &n);
    r =(R*sin(3.14159265/n))/(1+sin(3.14159265/n)) ; /// Your code goes here
    printf("r = %f\n", r);
    return 0;
}
