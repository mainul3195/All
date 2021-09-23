#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
	return a>b;
}
void execute()
{
	int n;
	string s;
	cin >> s;
	vector <int> v;
	v.push_back(0);
	int i,j,k;
	n=s.size();
	for(i=0; i<n; i++)
	{
		int count=0;
		if(s[i]=='1')
		{
			while(s[i++]=='1')
				count++;
			v.push_back(count);
			i--;
		}
	}
	sort(v.begin(), v.end(), cmp);
	int ans=0;
	k=v.size();
	for(i=0; i<k; i++)
		if(!(i%2))
			ans+=v[i];
	cout << ans << "\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		execute();
	return 0;
}