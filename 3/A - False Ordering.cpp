#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first==b.first)
		return a.second>b.second;
	return a.first<b.first;
}
int main()
{
	vector< pair<int, int > > n(1001);
	int j=0;
	for(int i=0; i<=1000; i++)
	{
		n[i].first=1;
		n[i].second=j++;
	}
	for(int i=2; i<=1000; i++)
		for(int j=i; j<=1000; j+=i)
			n[j].first++;
	sort(n.begin()+1, n.end(), cmp);
	int t;
	cin >> t;
	int x=0;
	while(t--)
	{
		int num;
		cin >> num;
		cout << "Case " << ++x << ": ";
		cout << n[num].second << "\n";
	}
	return 0;
}