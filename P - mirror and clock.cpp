#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,h,m;
	cin >> t;
	while(t--)
	{
		scanf("%d:%d ", &h, &m);
		if((h==12 || h==6) && !m)
			h=h;
		else if((h==12 || h==6) && m)
			h--;
		else 
		{
			h= 12-h;
			if(m)h--;
		}
		m=60-m;
		if(m==60) m=0;
		if(!h) h=12;
		printf("%02d:%02d\n", h, m);
	}
	return 0;
}