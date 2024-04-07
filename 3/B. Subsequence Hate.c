#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,j,l,t1,t2, a, b;
	char s[1001],c;
	scanf("%d", &t);
	while(t--)
	{
		int onec=0, zeroc=0;
		scanf("%s", s);
		l = strlen(s)-1;
		for(i=0; i<=l; i++)
		{
			if(s[i]=='0') zeroc++;
			else onec++;
		}
		if(s[0]=='1'&&s[l]=='1' ||s[0]=='0'&&s[l]=='0' || onec==l+1 || zeroc==l+1)
		{
			if(s[0]=='0') zeroc--;
			else onec--;
			printf("%d\n", onec>zeroc?zeroc:onec);
		}
		else
		{
			if(s[0]=='1')
			{
				for(i=l-1; s[i]=='0'; i--);
				t1 = zeroc - l+i;
				for(i=1; s[i]=='1'; i++);
				t2 = onec - i;
			}
			else
			{
				for(i=l-1; s[i]=='1'; i--);
				t1 = onec - l+i;
				for(i=1; s[i]=='0'; i++);
				t2 = zeroc - i;
			}
			printf("%d\n", t1>t2?t2:t1);
		}
	}
	return 0;
}