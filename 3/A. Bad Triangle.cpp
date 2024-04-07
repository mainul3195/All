#include<bits/stdc++.h>
using namespace std;

void execute()
{
	int n;
	cin >> n;
	vector <int> v;
	int i,j,k;
	for(i=0; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
	}
	if(v[0]+v[1]<=v[n-1])
		cout << "1 2 " << n << "\n";
	else
		cout << "-1\n";
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