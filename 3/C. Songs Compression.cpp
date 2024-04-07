#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> v;
	int j,k;
	long long tot=0, rtot=0;	
	for(int i=0; i<n; i++)
	{
		cin >>  j >> k;
		tot+=j;
		rtot+=k;
		v.push_back(j-k);
	}
	if(rtot>m)
	{
		cout << "-1\n";
		return 0;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int count=0;
	tot-=m;
	int i=0;
	while(tot>0)
	{
		count++;
		tot-=v[i++];
	}
	cout << count << "\n";
	return 0;
}