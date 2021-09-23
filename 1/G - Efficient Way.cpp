#include<bits/stdc++.h>
using namespace std;
bool cmp(pair < int, int> p1, pair < int, int> p2)
{
	return p1.first<p2.first;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	pair < int, int > p;
	vector < pair < int, int > > v;
	int i,j,k,n,m;
	cin >> n;
	for(i=1; i<=n; i++)
	{
		cin >> j;
		p=make_pair(j, i);
		v.push_back(p);
	}
	sort(v.begin(), v.end(), cmp);
	long long f_cnt=0, s_cnt=0;
	cin >> m;
	while(m--)
	{
		cin >> j;
		int l=0, h=n-1, mid;
		while(l<=h)
		{
			mid= l+(h-l)/2;
			if(v[mid].first==j)
			{
				i=v[mid].second;
				break;
			}
			else if(v[mid].first<j)
				l=mid+1;
			else
				h=mid-1;
		}
		f_cnt+=i;
		s_cnt+=n-i+1;
	//	cout << f_cnt << " " << s_cnt<< "\n";

	}
	cout << f_cnt << " " << s_cnt;

	return 0;
}