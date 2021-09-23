#include<stdio.h>
#include<string.h>
int main()
{
    char str[101];
    int t, result[101], count, i, j, start,len, end;

    scanf("%d", &t);
    for (i=0; i<t; i++)
    {
        count=0;
        start=0;
        end=0;
        scanf("%s", str);
        len=strlen(str);
        for(j=0; j<len; j++)
        {
            if(str[j]=='1')
            {
                start=j;
                break;
            }
        }
        for(j=len-1; j>=0; j--)
        {
            if(str[j]=='1')
            {
                end=j;
                break;
            }
        }

        for(j=start+1; j<end; j++)
        {
            if(str[j]=='0')
            {
                count++;
            }
        }
        result[i]=count;
    }

    for(i=0; i<t; i++)
        printf("%d\n", result[i]);

    return 0;
}
