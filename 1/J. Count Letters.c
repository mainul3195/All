#include<stdio.h>
char s[10000002];
int main()
{
	scanf("%s", s);
	int ar[26]={0},i=0;
	while(s[i])
		ar[s[i++]-97]++;
	for(i=0; i<26; i++)
		if(ar[i])
			printf("%c : %d\n", i+97, ar[i]);
	return 0;
}