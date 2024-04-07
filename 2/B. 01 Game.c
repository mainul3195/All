#include<stdio.h>
void execute();
int main()
{
	int t;
	scanf("%d ", &t);
	while(t--)
		execute();
	return 0;
}
void execute()
{
	char c[102];
	int c1,c0,dif,i;
	c1=c0=0;
	scanf("%s", c);
	for(i=0; c[i]; i++)
	{
		if(c[i]=='1')c1++;
		else c0++;
	}	
	//printf("%d %d\n", c0, c1);
	if(c1>c0)
		dif=c0;
	else
		dif=c1;
	
	if(dif%2) printf("DA\n");
	else printf("NET\n");
	return;
}