#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h,m,d;
	float deg;
	while(1)
	{
		scanf("%d:%d", &h, &m);
		if(!h && !m)
			return 0;
		deg=(11*m-60*h)/2.0;
		if(deg<0) deg*=-1;
		if(deg>180) deg = 360-deg;
		printf("%.3f\n", deg);
	}
}
