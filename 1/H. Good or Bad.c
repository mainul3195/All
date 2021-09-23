#include<stdio.h>
void execute()
{
	char s[100002];
	scanf("%s", s);
	int i, j=0;
	while(s[++j]!=0);
	for(i=0; i+2<j; i++)
		if(s[i]==48&&s[i+1]==49&&s[i+2]==48 || s[i]==49&&s[i+1]==48&&s[i+2]==49)
		{
			printf("Good\n");
			return;
		}
	printf("Bad\n");
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