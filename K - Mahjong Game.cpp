#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	pair < char , int > p;
	vector < pair < char , int> > v;
	int i,j,k;
	char c;
	for(i=0; i<3; i++)
	{
		cin >> j >> c;
		p = make_pair(c, j);
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	if((v[0].first==v[1].first && v[1].first==v[2].first) && ( (v[0].second==v[1].second && v[1].second==v[2].second)|| (v[2].second-v[1].second==1 && v[1].second-v[0].second==1)))
	{
		cout << "0";
		return 0;
	}
	for(i=1; i<3; i++)
		if(v[i].first==v[i-1].first && ( v[i].second==v[i-1].second || v[i].second-v[i-1].second==1 ||  v[i].second-v[i-1].second==2))
		{
			cout << "1";
			return 0;
		}
	cout << "2";
	return 0;
}