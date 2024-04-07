#include<stdio.h>
#include<math.h>
int main()
{
	int a[11][11], n, d, i, j, k, t, sum, num, count=0;
	double dis;
	scanf("%d %d", &n, &d);
	for(i=0; i<n; i++)
		for(j=0; j<d; j++)
			scanf("%d", &a[i][j]);

	for(i=1; i<n; i++)
	{
		for(k=0;k<i;k++)
		{
			sum = 0;
			for(j=0; j<d; j++)
				sum += (a[i][j]-a[k][j])*(a[i][j]-a[k][j]);
			dis = sqrt(sum);
			if(floor(dis)==dis)
				count++;	
		}
			
	}
	printf("%d\n", count);
	return 0;
}