#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    printf("Enter first number :");
    scanf("%d",&a);
    printf("Enter second number :");
    scanf("%d",&b);
    if(a>b){

        printf("%d is maximum\n ",a);
        printf("%d is minimum number\n",b);
    }
    else if (a<b){

        printf("%d is maximum\n ",b);
        printf("%d is minimum\n",a);
    }
    else {

        printf("Both  are equal\n");
    }
    return 0;

}
