#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long gcd(long long a, long long b)
{
	if(!b)
		return a;
	return gcd(b, a%b);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long x,y,k,mn,i,j;
		cin >> x >> y >> k;
		mn=gcd(x,y);
		vector<long long>v;
		for(i=1; i*i<=mn; i++)
			if(!(mn%i))
			{
				v.push_back(i);
				j=mn/i;
				if(i!=j)
					v.push_back(j);
			}
		int tot=v.size();
		sort(v.begin(), v.end());
		// for(i=0; i<tot; i++)
		// 	cout << v[i] << " \n"[i==tot-1];
		if(k>tot)
			cout << "-1\n";
		else
			cout << v[tot-k] << "\n";
	}
	return 0;
}