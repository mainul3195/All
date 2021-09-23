#include<stdio.h>
void execute()
{
	int i;
	scanf("%d", &i);
	if(!(i%4)) printf("YES\n");
	else printf("NO\n");
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