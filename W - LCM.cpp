#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
	if(!b)
		return a;
	return gcd(b, a%b);
}
long long lcm(long long a, long long b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long x;
	cin >> x;
	vector<long long> v;
	long long i;
	for(i=1; i*i<=x; i++)
		if(!(x%i))
			v.push_back(i);
	int tot=v.size();
	for(i=tot-1; i>=0; i--)
		if(lcm(v[i], x/v[i])==x)
		{
			cout << v[i] << " " << x/v[i];
			break;
		}
	return 0;
}