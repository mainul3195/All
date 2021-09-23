#include<stdio.h>
int main()
{
	char a[102], h[7]="hello";
	int i,j,f=0;
	scanf("%s", a);
	for(i=0,j=0; a[i]!='\0'; i++)
	{
		if(a[i]==h[j])
		{
			j++;
			if(j==5)
			{
				f=1;
				break;
			}
		}
	}
	if(f)
		printf("YES");
	else
		printf("NO");
	return 0;
}