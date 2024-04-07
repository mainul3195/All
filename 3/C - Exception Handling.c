#include<stdio.h>
int main()
{
	int max1=0, ar[200002], max2=0, maxcounter, n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", ar+i);
		if(ar[i]>max1)
		{
			max2 = max1;
			max1 = ar[i];
			maxcounter = 1;
		}
		else if(ar[i] == max1)
			maxcounter++;
		else if(ar[i]>max2)
			max2 = ar[i];
	}
	if(maxcounter>1)
		while(n--) printf("%d\n", max1);
	else
	{
		for(i=0; i<n; i++)
		{
			if(ar[i]==max1)
				printf("%d\n", max2);
			else 
				printf("%d\n", max1);
		}
	}
	return 0;
}