#include<stdio.h>
int main()
{
    int t, a, b, move;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &a, &b);
        if(a%b==0)
            move=0;
        else
        {
            move=((a/b)+1)*b-a;
        }
        printf("%d\n", move);

    }
    return 0;

}
