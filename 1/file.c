#include<stdio.h>
int main()
{
	int x, *p,y;
	char c;
	FILE *fin = fopen("fin.txt", "r+"), *fout;
	fout = fopen("fout.txt", "w+");
	while(!feof(fin))
	{
		fscanf(fin,"%c %d %d\n",&c, &x, &y);
		//printf("%c %d %d\n", c,x,y);
		if(c=='+') fprintf(fout,"%d + %d = %d\n",x,y, x+y); 
		else if(c=='-') fprintf(fout,"%d - %d = %d\n", x,y,x-y);
		else if(c=='*') fprintf(fout,"%d * %d = %d\n",x,y, x*y);
		else if(c=='/') fprintf(fout,"%d / %d = %d\n", x,y,x/y);
		else fprintf(fout,"c = :%c:, x = :%d:, y = :%d:\n", c, x, y);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}