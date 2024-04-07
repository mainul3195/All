#include <stdio.h>
#include<math.h>

int main()
{
    float R1, R2, R3, area, a, b, c, A, B, C;
    scanf("%f %f %f", &R1, &R2, &R3 );
    a=R1+R2;
    b=R2+R3;
    c=R3+R1;
    A=acos((b*b+c*c-a*a)/(2*b*c));
    B=acos((-b*b+c*c+a*a)/(2*a*c));
    C=acos((b*b-c*c+a*a)/(2*b*a));


    area = .5*(a*b*sin(C)-(R1*R1*B+R2*R2*C+R3*R3*A)) ; /// Your code goes here
    printf("Area = %f\n", area);
    return 0;
}
