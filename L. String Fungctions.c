#include<stdio.h>
#include<string.h>
void pop_back(char s[])
{
	int i=0;
	while(s[++i]);
	s[i-1]=0;
	return;
}
void back(char s[])
{
	int i=0;
	while(s[++i]);
	printf("%c\n", s[i-1]);
	return;
}
void sort(char s[], int a, int b)
{
	int i, j;
	for(i=a; i<b; i++)
		for(j=i+1; j<=b; j++)
			if(s[i]>s[j])
				s[i]^=s[j]^=s[i]^=s[j];
	return;
}
void reverse(char s[], int a, int b)
{
	int m=(a+b+1)/2,i=a,j=b;
	while(i<m)
	{
		s[i]^=s[j]^=s[i]^=s[j];
		i++,j--;
	}
}
void push_back(char s[],char c)
{
	int i=0;
	while(s[++i]);
	s[i]=c;
	s[i+1]=0;
	return;
}
void substr(char s[], int a, int b)
{
	while(a<=b)
		printf("%c", s[a++]);
	puts("");
	return;
}
int main()
{
	int n,q,a,b;
	scanf("%d %d", &n, &q);
	char str[1003], t[15],c;
	scanf("%s", str);
	while(q--)
	{
		scanf(" %s", t);
		if(strcmp(t, "pop_back")==0)
			pop_back(str);
		else if(strcmp(t, "front")==0)
			printf("%c\n", str[0]);
		else if(strcmp(t,"back")==0)
			back(str);
		else if(strcmp(t,"sort")==0)
		{
			scanf(" %d %d ", &a, &b);
			a--,b--;
			sort(str,a,b);
		}
		else if(strcmp(t,"reverse")==0)
		{
			scanf(" %d %d ", &a, &b);
			a--,b--;
			reverse(str,a,b);
		}
		else if(strcmp(t, "print")==0)
		{
			scanf("%d ", &a);
			printf("%c\n", str[a-1]);
		}
		else if(strcmp(t,"push_back")==0)
		{
			scanf(" %c", &c);
			push_back(str, c);
		}
		else if(strcmp(t,"substr")==0)
		{
			scanf(" %d %d ", &a, &b);
			a--,b--;
			substr(str,a,b);
		}
		//puts(str);
	}
	return 0;
}
