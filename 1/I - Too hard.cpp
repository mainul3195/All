#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	vector < int > m1, m2 ,m3;
	vector <long long> inp, inp2(n+3,0);
	int i,j,l;
	inp.push_back(0);
	for(i=0; i<n; i++)
	{
		cin >> j;
		inp.push_back(j);
	}
	m1.push_back(0);
	m2.push_back(0);
	m3.push_back(0);
	//cout << n << " " << m << " " << k <<"\n";
	int t=0;
	while(t++<m)
	{
		cin >> i >> j >> l;
		m1.push_back(i);
		m2.push_back(j);
		m3.push_back(l);
	}
// for(i=0; i<=m; i++)
// 		cout << m1[i] << " " << m2[i] << " " << m3[i] << "\n";
	vector <long long> arr(m+3, 0);
	while(k--)
	{
		cin >> i >> j;
		//cout << i << " " << j << "\n";
		arr[i]++;
		arr[j+1]--;
		// for(i=0; i<=n; i++)
		// cout << arr[i] << " \n"[i==n];
	}
	for(i=1; i<m+3; i++)
		arr[i]+=arr[i-1];
// for(i=0; i<=n; i++)
// 		cout << arr[i] << " \n"[i==n];
	long long p;
// for(i=0; i<=n; i++)
// 	{
// 		p=m3[i]*arr[i];
// 		cout << p << " \n"[i==n];
// 	}
	for(i=1; i<=m; i++)
	{
		p=m3[i]*arr[i];
		inp2[m1[i]] += p;
		inp2[m2[i]+1] -= p;
	}
	for(i=1; i<=n; i++)
		inp2[i]+=inp2[i-1];
// for(i=0; i<=n; i++)
// 		cout << inp2[i] << " \n"[i==n];
	for(i=1; i<=n; i++)
		inp[i]+=inp2[i];
	for(i=1; i<=n; i++)
		cout << inp[i] << " \n"[i==n];
	return 0;
}