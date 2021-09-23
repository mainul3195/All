#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int )
{
	return a>b;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r,g,b;
	cin >> r >> g >> b;
	vector < int > red, green , blue,max;
	int i,j;
	for(i=0; i<r; i++)
	{
		cin >> j;
		red.push_back(j);
	}
	for(i=0; i<g; i++)
	{
		cin >> j;
		green.push_back(j);
	}
	for(i=0; i<b; i++)
	{
		cin >> j;
		blue.push_back(j);
	}
	sort(red.begin(), red.end(), cmp);
	sort(green.begin(), green.end(), cmp);
	sort(blue.begin(), blue.end(), cmp);
	int rend=red.size(), gend=green.size(), bend=blue.size(), rs=0,gs=0,bs=0;
	long long ans=0;
	while((rs<rend || gs<gend) && (gs<gend || bs<bend) && (bs<bend || rs<rend))
	{
		if(red[rs]>= blue[bs] && green[gs]>=blue[bs])
		{
			ans+=red[rs++]*green[gs++];
		}
	}
	return 0;
}