#include<stdio.h>
void execute()
{
	char str[102];
	scanf("%s", str);
	int i=0;
	while(str[++i]!=0);
	if(i>10) printf("%c%d%c\n", str[0], i-2, str[i-1]);
	else
		printf("%s\n", str);
	return;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		execute();
	return 0;
}