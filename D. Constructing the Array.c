#include<stdio.h>
#include<string.h>
main()
{
    char Name[30];
printf("Enter the name you want to check\n");
    scanf("%s",Name);
    if(strcmp(Name,"Mashrafi")==0)
    {
   printf("100% bad Mashrafi\n",Name);
    }
    else
    {
        printf("100 percentage good man");
    }
    return 0;
}
