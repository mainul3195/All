#include<stdio.h>
#include<math.h>
int prcheck(int n)
{
	int i, lim;
	lim = sqrt(n);
	if(!(n%2) && n!=2) return 0;
	for(i=3; i<=lim; i++)
		if(!(n%i)) return 0;
	return 1;
}
int main()
{
	int n;
	while(~scanf("%d" ,&n))
	{
		while(1)
			if(prcheck(n++)) break;
		printf("%d\n", --n);
	}
	return 0;
}