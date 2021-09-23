
#include<stdio.h>
int main()
{

        char r1[4], r2[4], r3[4];
        int cx=0,c0=0, i, win=0;
        scanf("%s %s %s", r1, r2, r3);


        for(i=0; i<4; i++)
        {
            if(r1[i]=='X')
                cx++;
            else if(r1[i]=='0')
                c0++;

            if(r2[i]=='X')
                cx++;
            else if(r2[i]=='0')
                c0++;

            if(r3[i]=='X')
                cx++;
            else if(r3[i]=='0')
                c0++;
        }

        if(r1[0]=='X'&&r2[0]=='X'&&r3[0]=='X')
        {
            win=1;

        }
        else if(r1[1]=='X'&&r2[1]=='X'&&r3[1]=='X')
        {
            win=1;

        }
        else if(r1[2]=='X'&&r2[2]=='X'&&r3[2]=='X')
        {
            win=1;

        }

        else if(r1[0]=='X'&&r1[1]=='X'&&r1[2]=='X')
        {
            win=1;

        }
        else if(r2[0]=='X'&&r2[1]=='X'&&r2[2]=='X')
        {
            win=1;

        }
        else if(r3[0]=='X'&&r3[1]=='X'&&r3[2]=='X')
        {
            win=1;

        }
        else if(r1[0]=='X'&&r2[1]=='X'&&r3[2]=='X')
        {
            win=1;

        }
        else  if(r1[2]=='X'&&r2[1]=='X'&&r3[0]=='X')
        {
            win=1;

        }


        if(r1[0]=='0'&&r2[0]=='0'&&r3[0]=='0')
        {
            win=2;

        }
        else if(r1[1]=='0'&&r2[1]=='0'&&r3[1]=='0')
        {
            win=2;

        }
        else if(r1[2]=='0'&&r2[2]=='0'&&r3[2]=='0')
        {
            win=2;

        }

        else if(r1[0]=='0'&&r1[1]=='0'&&r1[2]=='0')
        {
            win=2;

        }
        else if(r2[0]=='0'&&r2[1]=='0'&&r2[2]=='0')
        {
            win=2;

        }
        else if(r3[0]=='0'&&r3[1]=='0'&&r3[2]=='0')
        {
            win=2;

        }
        else    if(r1[0]=='0'&&r2[1]=='0'&&r3[2]=='0')
        {
            win=2;

        }
        else  if(r1[2]=='0'&&r2[1]=='0'&&r3[0]=='0')
        {
            win=2;

        }


        if((win==1&&cx==c0)||(win==2&&cx==c0+1)||cx<c0||cx>c0+1)
            printf("illegal\n");
        else
        {
            if(win==1)
                printf("the first player won\n");
            else if(win==2)
                printf("the second player won\n");

            else if(cx+c0==9)
                printf("draw\n");
            else if(cx==c0)
                printf("first\n");
            else if(cx==c0+1)
                printf("second\n");

        }

}
