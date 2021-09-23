#include<stdio.h>
void execute(int);
int main()
{
	int t,i=0;
	scanf("%d", &t);
	while(t--)
		execute(++i);
	return 0;
}
void execute(int cn)
{
	int n,k,a,r=0,i,c=0,nod=0;
	scanf("%d %d", &n, &k);
	a=n;
	while(n!=0)
	{
		n/=10;
		nod++;
	}
	//printf("%d\n", nod);
	for(i=0; i<nod; i++)
		r=r*10+k;
	//printf("%d\n", a);
	while(1)
	{
		//printf("%d\n", r);
		if(r<a)
		{
			nod++;
			r=r*10+k;
		}
		//printf("%d\n", r);
		if(!(r%a)) break;
		r%=a;
		//printf("%d %d\n", r,nod);
	}
	printf("Case %d: %d\n", cn,nod);
	return;
}