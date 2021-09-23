#include<stdio.h>
int main()
{
	char c;
	int a[26]={0},i;
	while(~scanf("%c", &c))
		a[c-97]++;
	for(i=0; i<26; i++)
		if(a[i]==0)
		{
			printf("%c\n", i+97);
			break;
		}
	if(i==26) printf("None\n");
	return 0;
}