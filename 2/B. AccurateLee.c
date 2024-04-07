#include<stdio.h>
char a[100003];
void execute()
{
	int i,j,l=0,n,start;
	scanf("%d ", &n);
	scanf("%s", a);
	while(a[++l]);
	for(i=0; i<l && a[i]!='1'; i++);
	for(j=l-1; j>=0 && a[j]!='0';j--);
		//printf("i = %d  j = %d l = %d\n", i, j,l);
	if(i==l || j==-1 ||j<i) 
	{
		//printf("yesman\n");
		puts(a);
	}
	else
	{
		for(start=0; start<i; start++)
			printf("%c", a[start]);
		for(start=j; start<l; start++)
			printf("%c", a[start]);
		puts("");
	}
	return ;
}

int main()
{
	int t;
	scanf("%d ", &t);
	while(t--)
		execute();
	return 0;
}