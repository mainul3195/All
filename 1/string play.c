#include<stdio.h>
#include<string.h>
int main()
{
    char a[110];
    int t,l;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", a);
        l=strlen(a);
        if(l>10)
        {
            printf("%c%d%c\n", a[0], l-2, a[l-1]);
        }
        else
            puts(a);
    }
    return 0;

}
