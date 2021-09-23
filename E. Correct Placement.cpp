#include<bits/stdc++.h>
using namespace std;
struct per{
	int h, w, ind;
};
bool cmp1(per a, per b)
{
	if(a.h==b.h)
		return a.w<b.w;
	return a.h<b.h;
}
bool cmp2(per a, per b)
{
	if(a.w==b.w)
		return a.h<b.h;
	return a.w<b.w;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<per> mn, sh, sw;
		for(int i=1; i<=n; i++)
		{
			int j, k;
			cin >>  j >> k;
			mn.push_back({j, k, i});
			sh.push_back({j, k, i});
			sw.push_back({j, k, i});
		}
		sort(sh.begin(), sh.end(), cmp1);
		sort(sw.begin(), sw.end(), cmp2);
		for(int i=0; i<n; i++)
		{
			if(i)
				cout << " ";
			if(sh[0].h<mn[i].h && sh[0].w<mn[i].w || sh[0].w<mn[i].h && sh[0].h<mn[i].w)
				cout << sh[0].ind;
			else if(sw[0].h<mn[i].h && sw[0].w<mn[i].w ||sw[0].w<mn[i].h && sw[0].h<mn[i].w)
				cout << sw[0].ind;
			else
				cout << "-1";
		}
		cout << "\n";
	}
	return 0;
}