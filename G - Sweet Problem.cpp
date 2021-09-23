#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,a[4],c,i,j,k,count=0;
	cin >> n;
	while(n--)
	{
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);
		i=a[0], j=a[1], k=a[2];
		if(i+j<=k)
		{
			c=i+j;
			cout << c << "\n";
		}
		else
		{
			c=k-j;
			count=c;
			i-=c;
			k-=c;
			c=j-i;
			count+=c;
			j-=c;
			k-=c;
			count+=(i+j+k)/2;
			cout << count << "\n";
		}
	}
	return 0;
}