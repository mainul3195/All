#include<stdio.h>
int main()
{
	int i,n,a,b,c,x,y,z;
	x=y=z=0;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		x+=a; y+=b; z+=c;
	}
	if(!x && !y && !z)
		printf("YES");
	else
		printf("NO");
	return 0;
}