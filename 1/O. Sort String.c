#include<stdio.h>
int main()
{
	int a[26]={0},n,i;
	char c;
	scanf("%d ", &n);
	while(n--)
	{
		scanf("%c", &c);
		a[c-97]++;
	}
	for(i=0; i<26; i++)
		if(a[i])
			while(a[i]--)
				printf("%c", i+97);
	return 0;
}