#include<stdio.h>
int main()
{
    float mark;
    scanf("%f", &mark);
    if(mark>=80)
        printf("Letter Grade A+\nGrade Point 4.00");
    else if(mark>=75)
        printf("Letter Grade A\nGrade Point 3.75");
    else if(mark>=70)
        printf("Letter Grade A-\nGrade Point 3.50");
    else if(mark>=65)
        printf("Letter Grade B+\nGrade Point 3.25");
    else if(mark>=60)
        printf("Letter Grade B\nGrade Point 3.00");
    else if(mark>=55)
        printf("Letter Grade B-\nGrade Point 2.75");
    else if(mark>=50)
        printf("Letter Grade C+\nGrade Point 2.50");
    else if(mark>=45)
        printf("Letter Grade C\nGrade Point 2.25");
    else if(mark>=40)
        printf("Letter Grade C-\nGrade Point 2.00");
    else
        printf("Letter Grade F\nGrade Point 0.00");

        return 0;



}
