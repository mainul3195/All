#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0) ;cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		long long k,j;
		cin >> k;
		int i;
		vector <long long> v;
		for(i=0; i<n ;i++)
		{
			cin >> j;
			v.push_back(j);
		}
		long long max=-3e18;
		for(i=0; i<n ;i++)
			if(v[i]>max)
				max=v[i];
		for(i=0; i<n; i++)
			v[i]=max-v[i];
		if(!(k%2))
		{
			max=-3e18;
			for(i=0; i<n ;i++)
				if(v[i]>max)
					max=v[i];
			for(i=0; i<n; i++)
				v[i]=max-v[i];
		}
		for(i=0; i<n; i++)
			cout << v[i] << " \n"[i==n-1];
	}
	return 0;
}