#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,t;
    char n1[25],n2[25];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s %s", n1, n2);
        if(strlen(n1)==strlen(n2))
        {
            for(i=0;n1[i]!='\0';i++)
            {
                if(n1[i]=='a'||n1[i]=='e'||n1[i]=='i'||n1[i]=='o'||n1[i]=='u'||n1[i]=='A'||n1[i]=='E'||n1[i]=='I'||n1[i]=='O'||n1[i]=='U')
                    n1[i]='a';
                if(n2[i]=='a'||n2[i]=='e'||n2[i]=='i'||n2[i]=='o'||n2[i]=='u'||n2[i]=='A'||n2[i]=='E'||n2[i]=='I'||n2[i]=='O'||n2[i]=='U')
                    n2[i]='a';
            }
            if(strcmp(n1,n2)==0)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
                printf("No\n");



    }
    return 0;

}
