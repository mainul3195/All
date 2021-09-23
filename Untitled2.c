#include <stdio.h>

void reverse(void);

int main()
{
	reverse();
	return 0;
}
void reverse(void)
{
	char c;
	if((c=getchar())!='\n')
		reverse();
	putchar(c);
	return;
}
