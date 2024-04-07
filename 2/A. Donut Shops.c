#include<stdio.h>
void execute();
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		execute();
	return 0;
}
void execute()
{
	long long a,b,c;
	scanf("%lld %lld %lld", &a, &b, &c);
	if(a>=c) printf("-1 ");
	else printf("1 ");
	if(b*a<=c) printf("-1\n");
	else printf("%lld\n", b);
	return;
}