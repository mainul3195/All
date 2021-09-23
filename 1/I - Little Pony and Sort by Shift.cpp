#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>v(n);
	for(auto &i: v)
		cin >> i;
	int i;
	for(i=1; i<n; i++)
		if(v[i]<v[i-1])
			break;
	if(i==n)
		cout << "0\n";
	else
	{
		int tmp = i;
		for(i++; i<n; i++)
			if(v[i]<v[i-1])
				break;
		if(i==n && v[n-1]<=v[0])
			cout << n-tmp << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}