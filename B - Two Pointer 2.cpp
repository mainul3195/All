#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,i,j;
	long long c=0,k=0;
	vector<int> v;
	vector<long long>cum1;
	cin >> n;
	for(i=0; i<n ;i++)
	{
		cin >> j;
		v.push_back(j);
		cum1.push_back(k+j);
		k=cum1[i];
	}
	vector<long long>  cum2;
	for(i=n-1,k=0,j=0; i>=0; i--)
	{
		cum2.push_back(k+v[i]);
		k=cum2[j++];
	}
	reverse(cum2.begin(), cum2.end());
	k=cum2[0]/3;
	if(k*3==cum2[0])
	{
		for(i=0; i<n; i++)
			cum2[i]= cum2[i]==k? 1 : 0;
		for(i=1; i<n; i++)
			cum2[i]=cum2[i]+cum2[i-1];
		for(i=0; i<n-2; i++)
			if(cum1[i]==k)
				c+=cum2[n-1]-cum2[i+1];
	}
	cout << c;
	return 0;
}