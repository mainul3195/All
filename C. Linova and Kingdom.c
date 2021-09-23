#include<stdio.h>
void quick_sort(int[],int,int);
int partition(int[],int,int);
void swap(int, int);
int main()
{
	int i,tmp,j,k,f[200003]={0},cnt,a[200003],t,n,b,c,x,max=0;
	scanf("%d %d",&n,&x);
	for(i=1; i<n; i++)
	{
		scanf("%d %d", &c, &b);
		f[b]=c;
	}
	for(j=n;j>1;j--)
	{
		k=j;
		cnt=1;
		while(f[k]!=1)
		{
			cnt++;
			k=f[k];
		}
		a[j]=cnt;
	}
	a[0]=0;
	a[1]=1;
	quick_sort(a,0,n);
	for(i=0; i<=n; i++)
		printf("%d%c", a[i], " \n"[i==n]);
	for(i=n;x!=0;x--,i--)
		max+=a[i];
	printf("%d\n", max);
	return 0;
}

void quick_sort(int a[],int l,int u)
{
	int j;
	if(l<u)
	{
		j=partition(a,l,u);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}

	return;
}
 
int partition(int a[],int start,int end)
{
	int pivotIndex=start, pivotValue=a[end],i,temp;
	for(i=start;i<end;i++)
	{
		if(a[i]<pivotValue)
		{
			temp=a[i];
			a[i]=a[pivotIndex];
			a[pivotIndex]=temp;
			pivotIndex++;
		}
	}

	temp = a[pivotIndex];
	a[pivotIndex]=a[end];
	a[end]=temp;

	return pivotIndex; 
}

