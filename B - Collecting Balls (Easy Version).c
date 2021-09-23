#include<stdio.h>
int main()
{
	int ar[101],s , t, n, k, i;
	while(~scanf("%d %d", &n, &k))
	{
		for(i=0; i<n; i++)
			scanf("%d", ar+i);
		s=0;
		while(--n>-1)
			s += ar[n] > (k-ar[n]) ? 2*(k-ar[n]) : 2*ar[n];
		printf("%d\n", s);
	}
	return 0;
}