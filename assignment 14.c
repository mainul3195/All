#include<stdio.h>
int main()
{
    FILE *fin,*fres,*flast;
    fin =  fopen("std_marks.txt","r+");
    fres = fopen("std_res.txt","w+");
    flast = fopen("std_marks_info.txt","w+");
    int n,m,i,age,weight;
    char name[20],dummy[20];
    if(fin == NULL)
        printf("Input file does not exist!\n");
    else
    {
        printf("Input file is opened.\n");
        fscanf(fin,"%d %d",&n,&m);
        int marks[n+1][m+1],j=0,tot[10000] = {0},sum = 0,p,tot_max = 0,max;
        if(fres == NULL)
            printf("Output std_res.txt file does not exist!");
        else
        {
            printf("Output std_res.txt file is created.\n");
            for(i=1; i<=n; i++)
            {
                j=0;
                sum=0;
                fscanf(fin,"%s",dummy);
                fscanf(fin,"%[^\n]%*c",name);
                fprintf(fres,"%s","Name : ");
                fputs(dummy,fres);
                fputs(name,fres);
                fprintf(flast,"%s","Name : ");
                fputs(dummy,flast);
                fputs(name,flast);
                fscanf(fin,"%d %d",&age,&weight);
                fprintf(flast,"\tAge : %d\t",age);
                while(j++ < m)
                {
                    fscanf(fin,"%d",&marks[i][j]);
                    p = marks[i][j];
                    sum+=p;
                    fprintf(fres,"\nMarks in exam-%d : %d",j,p);
                }
                tot[i] = sum;
                fprintf(fres,"\nTotal marks = %d\n",tot[i]);
                fprintf(flast,"Total marks = %d\n",tot[i]);
                if(tot_max<tot[i])tot_max = tot[i];
            }
            printf("TOTAL_HIGHEST_MARKS = %d\n",tot_max);
        }
        for(j=1; j<=m; j++)
        {
            max = 0;
            for(i=1; i<=n; i++)
            {
                if(max<marks[i][j])
                    max = marks[i][j];
            }
            printf("highest_marks-%d : %d\n",j,max);
        }
        fclose(fres);
        fclose(fin);
        fclose(flast);
    }
    return 0;
}
