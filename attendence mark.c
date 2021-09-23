
#include<stdio.h>
int main()
{
    float percentages;
    int total, present;
    printf("Enter total number of classed and number of attended classes");
    scanf("%d %d", &total, &present);
    percentages=((float)present/total)*100;
    if(percentages>=95)
        printf("Marks for class attendance is 10");
    else if(percentages>=90)
        printf("Marks for class attendance is 9");
    else if(percentages>=85)
        printf("Marks for class attendance is 8");
    else if(percentages>=80)
        printf("Marks for class attendance is 7");
    else if(percentages>=75)
        printf("Marks for class attendance is 6");
    else if(percentages>=70)
        printf("Marks for class attendance is 5");
    else if(percentages>=65)
        printf("Marks for class attendance is 4");
    else if(percentages>=60)
        printf("Marks for class attendance is 3");

    else
        printf("Marks for class attendance is 0");

        return 0;



}
