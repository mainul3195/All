#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,i,m;
	float t;
	while(~scanf("%d %d", &a, &b)){
		m=1;
		c=b;
		while(c!=0)
		{
			m*=10;
			c/=10;
		}
		m=m*a+b;
		t = sqrt(m);
		if(ceil(t)==t)
	    {
	        printf("Yes\n");
	    }
	    else
	    	printf("No\n");
	}
    return 0;
}