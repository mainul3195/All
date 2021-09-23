#include<stdio.h>
char a[3000001];
int main()
{
	int n,i,tot=0,j=0;
	scanf("%d %s", &n, a);
	while(a[++j]);
	for(i=0; i<j; i++)
	{
//		printf("i = %d ", i);
		if(a[i]=='V')
			tot+=5;
		else if(a[i]=='W')
			tot+=2;
		else if(a[i]=='X')
			i++;
		else if(a[i]=='Y')
		{
			i++;
			if(i<j)
			{
				a[j++]=a[i];
				a[j]=0;
			}
		}
		else if(a[i]=='Z')
		{
			i++;
			if(i<j)
			{
				if(a[i]=='V')
					tot/=5;
				else if(a[i]=='W')
					tot/=2;
				else i--;
			}
		}
//		printf("tot = %d\n", tot);
	}
	printf("%d", tot);
	return 0;
}