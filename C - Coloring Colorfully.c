#include<stdio.h>
int min(int a, int b)
{
	if(a<b) return a;
	else return b;
}
int main()
{
	int c1=0, c2=1, d, t, s;
	char c;
	scanf("%c", &c);
	if(c=='1')
		s = 1;
	else
		s = 0;
	while(~scanf("%c", &c))
	{
		if(c==(48+s))
			c1++;
		else c2++;
		s = (s+1)%2;
	}
	printf("%d\n", min(c1, c2));
	return 0;
}