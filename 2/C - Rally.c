#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,ar[101],i,sum;
	float c;
	while(~scanf("%d", &a)){
		sum=0;
		for(i=0; i<a; i++){
			scanf("%d", ar+i);
			sum+=ar[i];
		}
		c=(float)sum/a;
		if(c>((ceil(c)+floor(c))/2))
			b=ceil(c);
		else
			b=floor(c);
		sum=0;
		for(i=0; i<a; i++){
			sum+=pow(ar[i]-b, 2);
		}

		printf("%d\n", sum);
		
	}

	return 0;
}