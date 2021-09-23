#include<stdio.h>
#include<math.h>


int main(){
    int number,fastorial,temp;

    while(scanf("%d",&number)!=EOF){
        if((number>=0&&number<=7) || (number<0 && number%2==0))
            printf("Underflow!\n");
        else if(number==8)
            printf("40320\n");
        else if(number==9)
            printf("362880\n");
        else if(number==10)
            printf("3628800\n");
        else if(number==11)
            printf("39916800\n");
        else if(number==12)
            printf("479001600\n");
        else if(number==13)
            printf("6227020800\n");
        else
            printf("Overflow!\n");
    }

    return 0;
}
