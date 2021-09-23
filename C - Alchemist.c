#include<stdio.h>

int position(int a[], int start, int end)
{
	int pvalue= a[end], i, pindex,temp;
	for(i=pindex=start; i<end; i++)
	{
		if(a[i]<pvalue)
		{
			temp = a[i];
			a[i] = a[pindex];
			a[pindex] = temp;
			pindex++;
		}
	}
	temp = a[i];
	a[i] = a[pindex];
	a[pindex] = temp;
	return pindex;
}

void quicksort(int a[], int start, int end)
{
	if(start>=end) return;
	int index = position(a,start, end);
	quicksort(a,start, index-1);
	quicksort(a, index+1, end);
	return;
}

int main()
{
	int n,i, a[100];
	long long two, sum;
	while(~scanf("%d", &n))
	{
		for(i=0; i<n; i++)
			scanf("%d", a+i);
		quicksort(a,0,n-1);
		sum = a[0];
		for(i=two=1; i<n; i++)
		{
			sum += two*a[i];
			two *= 2;
		}
		double fin = (double)sum/two;
		printf("%lf\n", fin);
	}
	return 0;
}