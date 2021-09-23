#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n;
	int k;
	cin >> n >> k;
	vector<long long>v;
	for(long long i=1; i*i<=n; i++)
		if(!(n%i))
		{
			v.push_back(i);
			if(i!=n/i)
				v.push_back(n/i);
		}
	sort(v.begin(), v.end());
	if(k>v.size())
		cout << "-1";
	else
		cout << v[k-1];
	return 0;
}