#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *tmp, *arr[101];
	int i,j,n=-1,ar[101], pos[101], temp;
	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		arr[i] = (char *)malloc(12*sizeof(char));
		scanf("%s %d", arr[i], &ar[i]);
	}
	for(i=0; i<=n; i++)
		pos[i] = i+1;
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
		{
			if(strcmp(arr[i], arr[j])>0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;

				temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;

				temp = pos[i];
				pos[i] = pos[j];
				pos[j] = temp;
			}
			else if(strcmp(arr[i], arr[j])==0)
			{
				if(ar[i]<ar[j])
				{
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;

					temp = ar[i];
					ar[i] = ar[j];
					ar[j] = temp;

					temp = pos[i];
					pos[i] = pos[j];
					pos[j] = temp;
				}
			}
		}
	/*for(i=0; i<n; i++)
	{
		printf("%s %d\n", arr[i], ar[i]);
	}*/
	for(i=0; i<n; i++)
	{
		printf("%d\n", pos[i]);
	}
	return 0;
}