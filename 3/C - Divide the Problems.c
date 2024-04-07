#include<stdio.h>

int position(int ar[], int start, int end)
{
	int pvalue = ar[end], pindex,i,temp;
	for(i=pindex=start ; i<end; i++)
	{
		if(ar[i]< pvalue)
			{
				temp = ar[pindex];
				ar[pindex] = ar[i];
				ar[i] = temp;
				pindex++;
			}
	}
	temp = ar[pindex];
	ar[pindex] = ar[end];
	ar[end] = temp;

	return pindex;
}

void quicksort(int ar[], int start, int end)
{
	if(start>=end) return;

	int index = position(ar, start, end);

	quicksort(ar, start, index-1);
	quicksort(ar, index+1, end);

	return;
}
int main()
{
	int ar[100000], n, i,a,b;
	while(~scanf("%d", &n))
	{
		for(i=0; i<n; i++)
			scanf("%d", ar+i);
		if(n%2)
			printf("0\n");
		else
		{	
			quicksort(ar, 0, n-1);
			a=(n-1)/2;
			b=a+1;
			if(ar[a]==ar[b])			
				printf("0\n");
			else
				printf("%d\n", ar[b]-ar[a]);
		}
		
	}
	return 0;
}