#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; 
	cin >> n;
	vector < int> v;
	vector < long long > s1,s2;
	s1.push_back(0);
	s2.push_back(0);
	int i, k,j;
	long long p;
	for(i=0; i<n; i++)
	{
		cin >> j;
		p=s1[i]+j;
		s1.push_back(p);
		v.push_back(j);
	}
	sort(v.begin(), v.end());
	for(i=0; i<n; i++)
	{
		p=s2[i]+v[i];
		s2.push_back(p);
	}
	int q;
	//for(i=0; i<n+1; i++) cout << s1[i] << " " << s2[i] << "\n";
	cin >> q;
	while(q--)
	{
		cin >> i >> j >> k;
		if(i==1)
			p=s1[k]-s1[j-1];
		else p=s2[k]-s2[j-1];
		cout << p << "\n";
	}
	return 0;
}