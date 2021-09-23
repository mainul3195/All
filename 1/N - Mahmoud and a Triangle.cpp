#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,i;
	vector <int> v;
	cin >> n;
	int j=n;
	while(j--)
	{
		cin >> i;
		v.push_back(i);
	}
	sort(v.begin(), v.end(), greater<int>());
	int flag=0;
	for(i=2; i<n; i++)
	{
		if(v[i-2]<v[i-1]+v[i])
			{
				flag=1;
				break;
			}
	}
	if(flag) cout << "YES";
	else cout << "NO";
	return 0;
}