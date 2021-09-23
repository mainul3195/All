#include<bits/stdc++.h>
using namespace std;
vector<int> pf;
int find_factor(int n)
{
	while(!(n%2))
	{
		pf.push_back(2);
		n/=2;
	}
	for(int i=3; i*i<=n; i+=2)
	{
		while(!(n%i))
		{
			pf.push_back(i);
			n/=i;
		}
	}
	if(n!=1)
		pf.push_back(n);
	return pf.size();
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin >> n >> k;
	int nd=find_factor(n);
	// for(int i=0; i<nd; i++)
	// 	cout << pf[i] << " \n"[i==nd-1];
	if(nd<k)
	{
		cout << "-1\n";
		return 0;
	}
	for(int i=0; i<k-1; i++)
		cout << pf[i] << " ";
	int mul=1;
	for(int i=k-1; i<nd; i++)
		mul*=pf[i];
	cout << mul << "\n";
	return 0;
}