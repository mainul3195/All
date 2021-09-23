#include<stdio.h>
void swap(char *a, char *b)
{
	char t;
	t = *a;
	*a = *b;
	*b = t;
	return;
}
void permute(char a[], int start, int end)
{
	if(start == end)
	{
		puts(a);
		return;
	}
	int i,j;
	char t;
	for(i=start; i<=end; i++)
	{
		t = a[i];
		for(j=i;j-1>=start;j--)
			swap(a+(j-1), a+j);
		a[j]=t;
		permute(a, start+1, end);
		t = a[start];
		for(j=start;j+1<=i; j++)
			swap(a+(j+1), a+j);
		a[j]=t;
	}
}
int main()
{
	char a[]="12345678";
	permute(a, 0, 7);
	return 0;
}