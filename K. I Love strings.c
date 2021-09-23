#include<stdio.h>
void execute()
{
	char s[52], t[52];
	scanf("%s %s", s, t);
	int i=0,j=0,k;
	while(1)
	{
		k=1;
		if(s[i])
		{
			printf("%c", s[i++]);
			k=0;
		}
		if(t[j])
		{
			printf("%c", t[j++]);
			k=0;
		}
		if(k) 
		{
			puts("");
			return;
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		execute();
	return 0;
}