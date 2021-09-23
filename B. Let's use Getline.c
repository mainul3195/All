#include<stdio.h>
int main()
{
	char c;
	while(1)
	{
		scanf("%c", &c);
		if(c=='\\') return 0;
		printf("%c", c);
	}
}