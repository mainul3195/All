#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	set<long long> s;
	for(int i=0; i<2*n; i++)
	{
		long long j;
		cin >> j;
		s.insert(j);
	}
	for(auto i: s)
		cout << i << " ";
}