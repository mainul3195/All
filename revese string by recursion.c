#include <stdio.h>
int a=0;
int reverse(void);

int main()
{
	reverse();
	printf("\n%d", a);
	return 0;
}
int reverse(void)
{
	char c;
	if((c=getchar())!='\n')
		reverse();
	putchar(c);
	a++;
	return a;
}
