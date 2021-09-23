#include<stdio.h>
int position(int a[],int start,int end)
{
	int i,pindex,pvalue=a[end], temp;
	for(i=pindex=start; i<end; i++)
	{
		if(a[i]<pvalue)
		{
			temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	temp=a[i];
	a[i]=a[pindex];
	a[pindex]=temp;
	return pindex;
}

void quicksort(int a[], int start, int end)
{
	if(start>=end) return;
	int index = position(a, start, end);
	quicksort(a, start, index-1);
	quicksort(a, index+1, end);
	return;
}
int main()
{
	int n,k,a[100001]={0},i,min=2000000000;
	scanf("%d %d", &n, &k);
	k--;
	for(i=0; i<n; i++)
		scanf("%d", a+i);
	quicksort(a, 0, n-1);
	n-=k;
	for(i=0; i<n; i++)
		if(a[i+k]-a[i]<min)
			min=a[i+k]-a[i];
	printf("%d\n", min);
	return 0;
}