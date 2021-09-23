 #include<stdio.h>
 int main()
{
    int t=0,h,d,l,i,j, s;

    printf("%c\n", EOF);
    freopen("input.txt.txt", "r", stdin);
    while((d=scanf("%d %d", &l, &h)) && d != EOF)
    {
        s=0;
        for(j=l; j<=h; j++)
        {
            if(j%2==1)
                s+=j;
        }
        printf("Case %d: %d\n", t, s);
    }
    return 0;
}
