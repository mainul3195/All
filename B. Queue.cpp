#include<bits/stdc++.h>
using namespace std;
struct cont
{
	int num, ind, ans;
};
bool cmp1(cont a, cont b)
{
	if(a.num==b.num)
		return a.ind<b.ind;
	return a.num<b.num;
}
bool cmp2(cont a, cont b)
{
	return a.ind<b.ind;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<cont> v;
	for(int i=0; i<n; i++)
	{
		int j;
		cin >> j;
		v.push_back({j,i,0});
	}
	sort(v.begin(), v.end(), cmp1);
	int mx=v[0].ind;
	v[0].ans=-1;
	for(int i=1; i<v.size(); i++)
	{
		if(v[i].ind>mx)
		{
			v[i].ans=-1;
			mx=v[i].ind;
		}
		else
		{
			v[i].ans=mx-v[i].ind-1;
			mx=max(mx, v[i].ind);
		}
	}
	sort(v.begin(), v.end(), cmp2);
	for(int i=0; i<v.size(); i++)
		cout << v[i].ans << " \n"[i==v.size()-1];
	return 0;
}