#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector < int > v;
	int i,j;
	for(i=0; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
	}
	reverse(v.begin(), v.end());
	//for(i=0; i<n; i++) cout << v[i] << "\n";
	vector<long long> s;
	long long p;
	s.push_back(0);
	for(i=0;i<n; i++)
	{
		p=s[i]+v[i];
		s.push_back(p);
	}
	int q,k;
	cin >> q;
	while(q--)
	{
		cin >> i;
		if(i==2)
		{
			cin >> k;
			p=s[n]+k;
			s.push_back(p);
			n++;
		}
		else
		{
			//for(i=0; i<n; i++) cout << s[i] << " ";
			//cout << "\n";
			cin >> j >> k;
			j = n-j+1;
			k = n-k+1;
			p=s[j]-s[k-1];
			cout << p << "\n";
		}
	}
	return 0;
}