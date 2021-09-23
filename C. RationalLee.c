#include<stdio.h>
 
void mergesort(long long a[],long long i,long long j);
void merge(long long a[],long long i1,long long j1,long long i2,long long j2);
void execute();
long long  a[200004], b[200004],temp[200004];
int main()
{
	long long t;
	scanf("%lld", &t);
	while(t--)
		execute();
	return 0;
}
void execute()
{
	long long n,k,i,j, start, end;
	scanf("%lld %lld", &n, &k);
	long long count=0;
	for(i=0; i<n; i++) scanf("%d ", a+i);
	for(i=0; i<k; i++) scanf("%d ", b+i);
	mergesort(a,0,n-1);
	mergesort(b,0,k-1);
	start=0; end=n-1;
	i=0;
	while(b[i]==1&&i<k)
	{
		count+=2*a[end--];
		i++;
	}
	//printf("count = %d\n", count);
	/*while(i<k)
	{
		count+=a[start]+a[end--];
		start+=b[i++]-1;
	}*/
	for(i=k-1;i>=0;i--){
	    if(b[i]>=2){
	        count += a[start] + a[end--];
	        start += b[i] - 1;
	    }
	}
	printf("%lld\n", count);
	return ;
}
 
void mergesort(long long a[],long long i,long long j)
{
	long long mid;
		
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);	
		mergesort(a,mid+1,j);	
		merge(a,i,mid,mid+1,j);	
	}
}
 
void merge(long long a[],long long i1,long long j1,long long i2,long long j2)
{
	long long i,j,k;
	i=i1;	
	j=i2;	
	k=0;
	
	while(i<=j1 && j<=j2)	
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	
	while(i<=j1)	
		temp[k++]=a[i++];
		
	while(j<=j2)	
		temp[k++]=a[j++];
		
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}