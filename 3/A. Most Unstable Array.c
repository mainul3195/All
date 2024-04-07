#include<stdio.h>


void test(void)
{
	int m,n;
	scanf("%d %d", &n, &m);
	if(n==1) printf("0\n");
	else if(n==2) printf("%d\n", m);
	else printf("%d\n", 2*m);
	return;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}