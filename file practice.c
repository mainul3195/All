#include<stdio.h>
int main()
{
    int i,n,m,j,age, weight,tmark,thmark,tmp;
    char name[50];
    FILE *fin = fopen("std_marks.txt", "r+"), *fout1 = fopen("std_res.txt", "a+"), *fout2 = fopen("std_marks_info.txt", "a+");
    fscanf(fin, "%d %d\n", &n, &m);
    int b,c,d,e,mark[m];
    for(i=0; i<n; i++)
    {
        int hmark[m]= {0};
        fscanf(fin,"%s", name);
        for(j=0; name[j]!=','; j++);
        name[j]='\0';
        fscanf(fin,"%d, %d,",&age, &weight);
        tmark=0;
        printf("%s, %d, %d, ",name, age, weight);
        //fscanf(fin,"%d %d %d %d %d", mark, mark+1, &mark[2], &mark[3], &mark[4]);
        for(j=0; j<m; j++)
        {
            fscanf(fin, " %d,",&mark[j]);
            if(mark[j]>hmark[j])
                hmark[j]=mark[j];
            tmark+=mark[j];
        }
        printf("%s, %d, ", name, tmark);
        /*	for(j=0; j<m; j++)
        {
        	printf( "%d ",mark[j]);
        }*/
        for(j=0; j<m; j++)
            printf("%d%c", mark[j], ",\n"[j==m-1]);

    }

    fclose(fin);
    fclose(fout1);
    fclose(fout2);
    return 0;
}
