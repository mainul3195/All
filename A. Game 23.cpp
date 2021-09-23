#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long m,n; 
	cin >> n >> m;
	bool ok=1;
	if(m%n)
		ok=0;
	long long t=m/n;
	int count=0;
	while(!(t%2))
	{
		t/=2;
		count++;
	}
	while(!(t%3))
	{
		t/=3;
		count++;
	}
	if(t!=1)
		ok=0;
	if(ok)
		cout << count << "\n";
	else
		cout << "-1\n";
	return 0;
}