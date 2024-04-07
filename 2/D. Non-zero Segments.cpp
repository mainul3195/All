#in`clude<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int>track(n, 0);
	vector<long long>num(n);
	for(int i=0; i<n; i++)
		cin >> num[i];
	long long sum=0;
	for(int l=0, r=0; r<n; r++)
	{
		sum+=num[r];

	}
	return 0;
}