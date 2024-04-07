#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *s[101], *c;
	int n,i,l,j;
	scanf("%d %d", &n, &l);
	for(i=0; i<n; i++)
		s[i]= (char *)malloc((l+1)*sizeof(char));
	for(i=0; i<n; i++)
		scanf("%s", s[i]);
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
		{
			if(strcmp(s[i], s[j])>0)
			{
				c=s[i];
				s[i]=s[j];
				s[j]=c;
			}
		}
	for(i=0; i<n;i++)
		printf("%s", s[i]);
	return 0;
}