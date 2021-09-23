#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,t,k,d;
	cin >> n >> t >> k >> d;
	int total_time=t*((n+k-1)/k);
	if(total_time-d>t)
		cout << "YES\n";
	else 
		cout << "NO\n";
	return 0;
}