#include<stdio.h>
int main()
{
	int n,t=0,i;
	char ar[20];
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s ", ar);
		if(ar[0]=='T')
			t+=4;
		else if(ar[0]=='C')
			t+=6;
		else if(ar[0]=='O')
			t+=8;
		else if(ar[0]=='D')
			t+=12;
		else t+=20;
	}
	printf("%d", t);
	return 0;
}