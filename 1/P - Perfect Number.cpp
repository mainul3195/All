#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int i,k,count=0;
	cin >> k;
	for(i=19; ; i++)
	{
		int r, sum=0,j=i;
		while(j)
		{
			r=j%10;
			sum+=r;
			j/=10;
		}
		if(sum==10) count++;
		if(count==k) 
		{
			cout << i;
			return 0;
		}
	}
}