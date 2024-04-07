#include<stdio.h>
int main()
{
	int t, i, j;
	char n[10][10];
	scanf("%d", &t);
	while(t--)
	{
		for(i=0; i<9; i++)
		{
			scanf("%s", &n[i]);
			for(j=0; j<9; j++)
				n[i][j]=='1'?printf("2"):printf("%c",n[i][j]);
			printf("\n");
		}
	}

	return 0;
}