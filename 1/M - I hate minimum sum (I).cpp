#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector <long long> a, b(n+1,0);
	a.push_back(0);
	int i,j;
	for(i=0; i<n; i++)
	{
		cin >> j;
		a.push_back(j);
	}
	while(q--)
	{
		cin >> i >> j;
		b[i-1]++;
		b[j]--;
	}
	for(i=1; i<=n; i++)
		b[i] += b[i-1];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long sum=0;
	for(i=1; i<=n; i++)
		sum += a[i]*b[i];
	cout << sum;
	return 0;
}