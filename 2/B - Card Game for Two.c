#include<stdio.h>
int main()
{
	int a[101], n, i, k, j,t,s;
	while(~scanf("%d", &n))
	{
		for(i=0 ; i<n; i++)
			scanf("%d", a+i);
		for(i=0; i<n-1; i++)
			for(j=0; j<n-i-1; j++)
				if(a[j]<a[j+1])
					t = a[j],a[j] = a[j+1],a[j+1] = t;
		s = 0; k = -1;
		for(i=0; i<n; i++)
		{
			k*=-1;
			s+= k*a[i];
		}
		printf("%d\n", s);
	}
	return 0;
}