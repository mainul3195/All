#include<bits/stdc++.h>
using namespace std;
	int n, x, y;

long long calc(long long j, long long cng)
{
	return j*x+cng*y;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x >> y;
	string s;
	cin >> s;
	int n0=0, n1=0;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='0')
		{
			n0++;
			while(i+1<s.size()&& s[i+1]=='0') i++;
		}
		else if(s[i]=='1')
		{
			n1++;
			while(i+1<s.size()&& s[i+1]=='1') i++;
		}
	}
	long long mn=100000000000000000;
	if(!n0)
		mn=0;
	for(int reverse=n0-1,cng=1; reverse>=0; reverse--,cng++)
		mn=min(mn, calc(reverse,cng));
	cout << mn << "\n";
	return 0;
}