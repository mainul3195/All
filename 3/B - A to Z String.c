#include<stdio.h>
#include<string.h>
int main()
{
	char s[200001];
	scanf("%s", s);
	int i,j,l=strlen(s);
	for(i=0; i<l; i++)
		if(s[i]=='A')
			break;
	for(j=l-1; j>0; j--)
		if(s[j]=='Z')
			break;
	printf("%d\n", j-i+1);
	return 0;
}