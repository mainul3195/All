#include<stdio.h>
int main()
{
	char c[100003];
	int i=0;
	scanf("%s",c);
	while(c[i]!='\0')
	{
		if(c[i]==',')
			printf(" ");
		else if(c[i]<94)
			printf("%c", c[i]+32);
		else printf("%c", c[i]-32);

		i++;
	}
	return 0;
}