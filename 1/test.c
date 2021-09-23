#include<stdio.h>
int main()
{
int tmp[10], me, op, position, i;

//my win
    if(tmp[0]==me && tmp[1]==me)
    {
        if(tmp[2]==3)
            position = 2;
    }
    else if(tmp[1]==me && tmp[2]==me)
    {
        if(tmp[0]==3)
            position = 0;
    }
    else if(tmp[0]==me && tmp[2]==me)
    {
        if(tmp[1]==3)
            position = 1;
    }

    else if(tmp[3]==me && tmp[4]==me)
    {
        if(tmp[5]==3)
            position = 5;
    }
    else if(tmp[4]==me && tmp[5]==me)
    {
        if(tmp[3]==3)
            position = 3;
    }
    else if(tmp[3]==me && tmp[5]==me)
    {
        if(tmp[4]==3)
            position = 4;
    }

    else if(tmp[6]==me && tmp[7]==me)
    {
        if(tmp[8]==3)
            position = 8;
    }
    else if(tmp[7]==me && tmp[8]==me)
    {
        if(tmp[6]==3)
            position = 6;
    }
    else if(tmp[6]==me && tmp[8]==me)
    {
        if(tmp[7]==3)
            position = 7;
    }

    else if(tmp[0]==me && tmp[3]==me)
    {
        if(tmp[6]==3)
            position = 6;
    }
    else if(tmp[3]==me && tmp[6]==me)
    {
        if(tmp[0]==3)
            position = 0;
    }
    else if(tmp[0]==me && tmp[6]==me)
    {
        if(tmp[3]==3)
            position = 3;
    }


    else if(tmp[4]==me && tmp[1]==me)
    {
        if(tmp[7]==3)
            position = 7;
    }
    else if(tmp[1]==me && tmp[7]==me)
    {
        if(tmp[4]==3)
            position = 4;
    }
    else if(tmp[4]==me && tmp[7]==me)
    {
        if(tmp[1]==3)
            position = 1;
    }


    else if(tmp[8]==me && tmp[5]==me)
    {
        if(tmp[2]==3)
            position = 2;
    }
    else if(tmp[5]==me && tmp[2]==me)
    {
        if(tmp[8]==3)
            position = 8;
    }
    else if(tmp[8]==me && tmp[2]==me)
    {
        if(tmp[5]==3)
            position = 5;
    }


    else if(tmp[0]==me && tmp[4]==me)
    {
        if(tmp[8]==3)
            position = 8;
    }
    else if(tmp[4]==me && tmp[8]==me)
    {
        if(tmp[0]==3)
            position = 0;
    }
    else if(tmp[0]==me && tmp[8]==me)
    {
        if(tmp[4]==3)
            position = 4;
    }


    else if(tmp[6]==me && tmp[4]==me)
    {
        if(tmp[2]==3)
            position = 2;
    }
    else if(tmp[4]==me && tmp[2]==me)
    {
        if(tmp[6]==3)
            position = 6;
    }
    else if(tmp[6]==me && tmp[2]==me)
    {
        if(tmp[4]==3)
            position = 4;
    }



//defence
    else if(tmp[0]==op && tmp[1]==op)
    {
        if(tmp[2]==3)
            position = 2;
    }
    else if(tmp[1]==op && tmp[2]==op)
    {
        if(tmp[0]==3)
            position = 0;
    }
    else if(tmp[0]==op && tmp[2]==op)
    {
        if(tmp[1]==3)
            position = 1;
    }

    else if(tmp[3]==op && tmp[4]==op)
    {
        if(tmp[5]==3)
            position = 5;
    }
    else if(tmp[4]==op && tmp[5]==op)
    {
        if(tmp[3]==3)
            position = 3;
    }
    else if(tmp[3]==op && tmp[5]==op)
    {
        if(tmp[4]==3)
            position = 4;
    }

    else if(tmp[6]==op && tmp[7]==op)
    {
        if(tmp[8]==3)
            position = 8;
    }
    else if(tmp[7]==op && tmp[8]==op)
    {
        if(tmp[6]==3)
            position = 6;
    }
    else if(tmp[6]==op && tmp[8]==op)
    {
        if(tmp[7]==3)
            position = 7;
    }

    else if(tmp[0]==op && tmp[3]==op)
    {
        if(tmp[6]==3)
            position = 6;
    }
    else if(tmp[3]==op && tmp[6]==op)
    {
        if(tmp[0]==3)
            position = 0;
    }
    else if(tmp[0]==op && tmp[6]==op)
    {
        if(tmp[3]==3)
            position = 3;
    }


    else if(tmp[4]==op && tmp[1]==op)
    {
        if(tmp[7]==3)
            position = 7;
    }
    else if(tmp[1]==op && tmp[7]==op)
    {
        if(tmp[4]==3)
            position = 4;
    }
    else if(tmp[4]==op && tmp[7]==op)
    {
        if(tmp[1]==3)
            position = 1;
    }


    else if(tmp[8]==op && tmp[5]==op)
    {
        if(tmp[2]==3)
            position = 2;
    }
    else if(tmp[5]==op && tmp[2]==op)
    {
        if(tmp[8]==3)
            position = 8;
    }
    else if(tmp[8]==op && tmp[2]==op)
    {
        if(tmp[5]==3)
            position = 5;
    }


    else if(tmp[0]==op && tmp[4]==op)
    {
        if(tmp[8]==3)
            position = 8;
    }
    else if(tmp[4]==op && tmp[8]==op)
    {
        if(tmp[0]==3)
            position = 0;
    }
    else if(tmp[0]==op && tmp[8]==op)
    {
        if(tmp[4]==3)
            position = 4;
    }


    else if(tmp[6]==op && tmp[4]==op)
    {
        if(tmp[2]==3)
            position = 2;
    }
    else if(tmp[4]==op && tmp[2]==op)
    {
        if(tmp[6]==3)
            position = 6;
    }
    else if(tmp[6]==op && tmp[2]==op)
    {
        if(tmp[4]==3)
            position = 4;
    }

//tricks


    else if(tmp[0]==me && tmp[2]==me && tmp[4]==3 &&tmp[5]==3)
    {
        if(tmp[8]==3)
            position = 8;
    }
    else if(tmp[0]==me && tmp[6]==me && tmp[4]==3 &&tmp[7]==3)
    {
        if(tmp[8]==3)
            position = 8;
    }




//defence triks
    else if(
        (tmp[0]==op && tmp[1]==3 &&tmp[2]==3 && tmp[3]==3 &&tmp[4]==3&& tmp[5]==3 &&tmp[6]==3&& tmp[7]==3 &&tmp[8]==3)
        ||
        (tmp[0]==3 && tmp[1]==op &&tmp[2]==3 && tmp[3]==3 &&tmp[4]==3&& tmp[5]==3 &&tmp[6]==3&& tmp[7]==3 &&tmp[8]==3)
    )
    {
        if(tmp[4]==3)
            position = 4;
    }
    else if((tmp[0]==3 && tmp[1]==op &&tmp[2]==3 && tmp[3]==3 &&tmp[4]==me&& tmp[5]==3 &&tmp[6]==3&& tmp[7]==3 &&tmp[8]==op)
            ||
            (tmp[0]==3 && tmp[1]==op &&tmp[2]==3 && tmp[3]==3 &&tmp[4]==3&& tmp[5]==3 &&tmp[6]==op&& tmp[7]==3 &&tmp[8]==3))
    {
        if(tmp[3]==3)
            position = 3;
    }



    //tricks super 7
    else if(tmp[0]==me && (tmp[1]==op || tmp[2] == op)&& tmp[4]==3 &&tmp[5]==3 && tmp[7]==3 && tmp[8]==3 && tmp[3]==3)
    {
        if(tmp[6]==3)
            position = 6;
    }
    else if(tmp[0]==me && (tmp[3]==op || tmp[6] == op)&& tmp[4]==3 &&tmp[5]==3 && tmp[7]== 3&& tmp[8]==3 && tmp[1]==3)
    {
        if(tmp[2]==3)
            position = 2;
    }
    else if(tmp[0]==me && (tmp[5]==op || tmp[8] == op)&& tmp[7]==3 &&tmp[3]==3 && tmp[6]== 3&& tmp[4]==3 && tmp[1]==3)
    {
        if(tmp[2]==3)
            position = 2;
    }
    else if(tmp[0]==me && tmp[7]==op && tmp[4]==3 &&tmp[5]==3 && tmp[3]== 3&& tmp[2]==3 && tmp[1]==3)
    {
        if(tmp[6]==3)
            position = 6;
    }

    //trick draw or win
    else if(tmp[0]==me && tmp[4]==op && tmp[2] == op && tmp[8]==me && tmp[3]==3 &&tmp[5]==3 && tmp[7]== 3&& tmp[1]==3)
    {
        if(tmp[6]==3)
            position = 6;
    }
    else if(tmp[0]==me && tmp[4]==op && tmp[6] == op && tmp[8]==me && tmp[3]==3 &&tmp[5]==3 && tmp[7]== 3&& tmp[1]==3)
    {
        if(tmp[2]==3)
            position = 2;
    }
    else if(tmp[0]==me && tmp[4]==op && tmp[6] == 3 && tmp[2]==3 && tmp[3]==3 &&tmp[5]==3 && tmp[7]== 3&& tmp[1]==3)
    {
        if(tmp[8]==3)
            position = 8;
    }
    else
        for(i=0; i<9; i++)
            if(tmp[i]==3)
                position = i;
    return 0;
}
