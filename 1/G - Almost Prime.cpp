#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,61,67,71,73};
	vector<int> v;
	int track[3001]={0};
	for(int i=1; i<=3000; i++)
	{
		int n=i;
		for(int j=0; prime[j]*prime[j]<=n; j++)
			if(!(n%prime[j]))
			{
				v.push_back(prime[j]);
				while(!(n%prime[j]) && n!=1)
					n/=prime[j];
			}
		if(n!=1)
			v.push_back(n);
		if(v.size()==2)
			track[i]=1;
		v.clear();
	}
	// for(int i=0; i<=30; i++)
	// 	cout << i << " = " << track[i] << "\n";
	for(int i=1; i<=3000; i++)
		track[i]+=track[i-1];
	int k;
	cin >> k;
	cout << track[k];
	return 0;
}