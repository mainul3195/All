#include<stdio.h>
char c[1000003];
int main()
{
	scanf("%[^\n]", c);
	int i=0, count=0;
	do
	{
		if(((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z'))&&((c[i+1]<'a'||c[i+1]>'z')&&(c[i+1]<'A'||c[i+1]>'Z')))
			count++;
	}while(c[++i]);
	printf("%d", count);
	return 0;
}